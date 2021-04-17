#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "run_config.h"
#include "cJSON/cJSON.h"

void preorder_print(node_t *n)
{
	if(!n) { 
		printf("_");
		return;
	}
	printf("%d(",n->id);
	preorder_print(n->l_c);
	printf(",");
	preorder_print(n->r_s);
	printf(")");
}

void deallocate(node_t *n)
{
	if(!n)
		return;
	deallocate(n->l_c);
	deallocate(n->r_s);
	free(n);
}	

int preorder_copy_ks(node_t *n)
{
	int ret;
	if(!n) { 
		//return to parent
		int no_id = -1;
		lt_t no_lt_t = 0;
                printf("run_add_node()\n");
		ret = run_add_node(&no_id, &no_lt_t, &no_lt_t, &no_id); 
                printf("run_add_node() return=%d\n", ret);
		return ((ret) ? 1 : 0);
	
	}
	ret = run_add_node(&n->id, &n->rate_a, &n->rate_b, &n->level);
	if (ret) return 1;
	ret = preorder_copy_ks(n->l_c);
	if (ret) return 1;
	ret = preorder_copy_ks(n->r_s);
	if (ret) return 1;
	return 0;
}

node_t *parse_object(cJSON *item, node_t* parent)
{
	int i;
	cJSON *children, *child;
	node_t *first, *prev, *tmp;
	
	first = prev = NULL;
	children = cJSON_GetObjectItem(item,"children");
	if (!children) return NULL;
	for (i = 0 ; i < cJSON_GetArraySize(children); i++)
	{			
		child = cJSON_GetArrayItem(children, i);
		
		tmp = malloc(sizeof(node_t));
		init(tmp);
		tmp->id     = cJSON_GetObjectItem(child,"id")->valueint;
		tmp->rate_a = cJSON_GetObjectItem(child,"cost")->valueint;
		tmp->rate_b = cJSON_GetObjectItem(child,"period")->valueint;
		tmp->level  = cJSON_GetObjectItem(child,"level")->valueint;
		tmp->parent = parent;
		
		if (!prev) {
			prev = tmp;
			first = tmp;
			
		} else {
			prev->r_s = tmp;
		}
		tmp->l_c = parse_object(child, tmp);
		prev = tmp;			
	}
	
	return first;
}

int main(int argc, char** argv)
{
	FILE *fp;
	long lSize;
	char *buffer;
	cJSON *root;
	node_t *root_node;
	int ret = 0;
	
	if (argc != 2) {
		printf("Error: Bad argument.\n");
        	printf("Usage: \n\t%s FILE\n", argv[0]);
        	printf("\nFILE must be a reduction tree in the JSON format.\n");
        	return 1;
        }
	fp = fopen(argv[1], "rb");
	if(!fp) perror(argv[1]),exit(1);

	fseek(fp, 0L, SEEK_END);
	lSize = ftell(fp);
	rewind(fp);

	/* allocate memory for entire content */
	buffer = calloc(1, lSize+1);
	if(!buffer) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

	/* copy the file into the buffer */
	if(1!=fread(buffer, lSize, 1, fp))
		fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);	

	fclose(fp);
	
	root = cJSON_Parse(buffer);
	root_node = malloc(sizeof(node_t));
	init(root_node);
	
	root_node->id	  = cJSON_GetObjectItem(root,"id")->valueint;
	root_node->rate_a = cJSON_GetObjectItem(root,"cost")->valueint;
	root_node->rate_b = cJSON_GetObjectItem(root,"period")->valueint;
	root_node->level  = cJSON_GetObjectItem(root,"level")->valueint;
	root_node->l_c = parse_object(root, root_node);
	
	printf("run_config: Reduction tree created\n");
	
	preorder_print(root_node);
	printf("\n");
	
	ret = preorder_copy_ks(root_node);
	if (ret)
		printf("Error: Reduction tree NOT cloned into the ks\n");
	else printf("Reduction tree cloned into the ks\n");
	
	deallocate(root_node);
	cJSON_Delete(root);
	free(buffer);
	
	return 0;
}

