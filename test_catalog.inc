#include "tests.h"
void test_set_rt_task_param_invalid_pointer(void);
void test_get_set_rt_task_param(void);
void test_set_rt_task_param_invalid_params(void);
void test_reject_bad_priorities(void);
void test_accept_valid_priorities(void);
void test_job_control_non_rt(void);
void test_rt_fork_non_rt(void);
void test_ctrl_page_writable(void);
void test_set_cpu_mapping(void);
void test_suspended_admission(void);
void test_running_admission(void);
void test_lock_fmlp_nesting(void);
void test_lock_fmlp_srp_nesting(void);
void test_lock_srp_nesting(void);
void test_lock_pcp_nesting(void);
void test_lock_mpcp_pcp_no_nesting(void);
void test_lock_fmlp_pcp_no_nesting(void);
void test_lock_dpcp_pcp_no_nesting(void);
void test_lock_mpcp_srp_no_nesting(void);
void test_lock_dpcp_srp_no_nesting(void);
void test_lock_fmlp_mpcp_no_nesting(void);
void test_lock_fmlp_dpcp_no_nesting(void);
void test_mpcp_nesting(void);
void test_mpcpvs_nesting(void);
void test_dpcp_nesting(void);
void test_dflp_nesting(void);
void test_lock_fmlp_dflp_no_nesting(void);
void test_lock_dflp_pcp_no_nesting(void);
void test_fmlp_not_active(void);
void test_invalid_od(void);
void test_invalid_obj_type(void);
void test_not_inherit_od(void);
void test_preempt_on_resume(void);
void test_jobs_are_rate_limited(void);
void test_jobs_are_rate_limited_synch(void);
void test_lock_pcp(void);
void test_pcp_bad_cpu(void);
void test_pcp_inheritance(void);
void test_srp_ceiling_blocking(void);
void test_lock_dpcp(void);
void test_dpcp_bad_cpu(void);
void test_lock_dpcp_pcp(void);
void test_not_lock_pcp_be(void);
void test_lock_mpcp(void);
void test_pcp_lock_mode_change(void);
void test_mpcp_lock_mode_change(void);
void test_dpcp_lock_mode_change(void);
void test_pcp_lock_teardown(void);
void test_dpcp_lock_teardown(void);
void test_mpcp_lock_teardown(void);
void test_not_lock_fmlp_be(void);
void test_not_lock_srp_be(void);
void test_lock_srp(void);
void test_lock_fmlp(void);
void test_lock_dflp(void);
void test_dflp_bad_cpu(void);
void test_srp_lock_mode_change(void);
void test_dflp_lock_mode_change(void);
void test_fmlp_lock_mode_change(void);
void test_srp_lock_teardown(void);
void test_fmlp_lock_teardown(void);
void test_dflp_lock_teardown(void);
struct testcase test_catalog[] = {
	{test_set_rt_task_param_invalid_pointer, "reject invalid rt_task pointers"},
	{test_get_set_rt_task_param, "read back rt_task values"},
	{test_set_rt_task_param_invalid_params, "reject invalid rt_task values"},
	{test_reject_bad_priorities, "reject invalid priorities"},
	{test_accept_valid_priorities, "accept lowest and highest valid priorities"},
	{test_job_control_non_rt, "reject job control for non-rt tasks"},
	{test_rt_fork_non_rt, "children of RT tasks are not automatically RT tasks"},
	{test_ctrl_page_writable, "tasks have write access to /dev/litmus/ctrl mappings"},
	{test_set_cpu_mapping, "task's CPU affinity is set to CPU set that is read from file"},
	{test_suspended_admission, "admission control handles suspended tasks correctly"},
	{test_running_admission, "admission control handles running tasks correctly"},
	{test_lock_fmlp_nesting, "FMLP no nesting allowed"},
	{test_lock_fmlp_srp_nesting, "FMLP no nesting with SRP resources allowed"},
	{test_lock_srp_nesting, "SRP nesting allowed"},
	{test_lock_pcp_nesting, "PCP nesting allowed"},
	{test_lock_mpcp_pcp_no_nesting, "PCP and MPCP nesting not allowed"},
	{test_lock_fmlp_pcp_no_nesting, "PCP and FMLP nesting not allowed"},
	{test_lock_dpcp_pcp_no_nesting, "PCP and DPCP nesting not allowed"},
	{test_lock_mpcp_srp_no_nesting, "SRP and MPCP nesting not allowed"},
	{test_lock_dpcp_srp_no_nesting, "SRP and DPCP nesting not allowed"},
	{test_lock_fmlp_mpcp_no_nesting, "MPCP and FMLP nesting not allowed"},
	{test_lock_fmlp_dpcp_no_nesting, "DPCP and FMLP nesting not allowed"},
	{test_mpcp_nesting, "MPCP no nesting allowed"},
	{test_mpcpvs_nesting, "MPCP-VS no nesting allowed"},
	{test_dpcp_nesting, "DPCP no nesting allowed"},
	{test_dflp_nesting, "DFLP no nesting allowed"},
	{test_lock_fmlp_dflp_no_nesting, "DFLP and FMLP nesting not allowed"},
	{test_lock_dflp_pcp_no_nesting, "PCP and DFLP nesting not allowed"},
	{test_fmlp_not_active, "don't open FMLP semaphores if FMLP is not supported"},
	{test_invalid_od, "reject invalid object descriptors"},
	{test_invalid_obj_type, "reject invalid object types"},
	{test_not_inherit_od, "don't inherit FDSO handles across fork"},
	{test_preempt_on_resume, "preempt lower-priority task when a higher-priority task resumes"},
	{test_jobs_are_rate_limited, "periodic jobs are rate-limited (w/o synchronous release)"},
	{test_jobs_are_rate_limited_synch, "periodic jobs are rate-limited (w/ synchronous release)"},
	{test_lock_pcp, "PCP acquisition and release"},
	{test_pcp_bad_cpu, "PCP reject bad CPU parameter"},
	{test_pcp_inheritance, "PCP priority inheritance"},
	{test_srp_ceiling_blocking, "SRP ceiling blocking"},
	{test_lock_dpcp, "DPCP acquisition and release"},
	{test_dpcp_bad_cpu, "DPCP reject bad CPU parameter"},
	{test_lock_dpcp_pcp, "DPCP-PCP interleaved priority"},
	{test_not_lock_pcp_be, "don't let best-effort tasks lock (D|M-)PCP semaphores"},
	{test_lock_mpcp, "MPCP acquisition and release"},
	{test_pcp_lock_mode_change, "PCP task becomes non-RT task while holding lock"},
	{test_mpcp_lock_mode_change, "MPCP task becomes non-RT task while holding lock"},
	{test_dpcp_lock_mode_change, "DPCP task becomes non-RT task while holding lock"},
	{test_pcp_lock_teardown, "PCP task exits while holding lock"},
	{test_dpcp_lock_teardown, "DPCP task exits while holding lock"},
	{test_mpcp_lock_teardown, "MPCP task exits while holding lock"},
	{test_not_lock_fmlp_be, "don't let best-effort tasks lock FMLP semaphores"},
	{test_not_lock_srp_be, "don't let best-effort tasks open SRP semaphores"},
	{test_lock_srp, "SRP acquisition and release"},
	{test_lock_fmlp, "FMLP acquisition and release"},
	{test_lock_dflp, "DFLP acquisition and release"},
	{test_dflp_bad_cpu, "DFLP reject bad CPU parameter"},
	{test_srp_lock_mode_change, "SRP task becomes non-RT task while holding lock"},
	{test_dflp_lock_mode_change, "DFLP task becomes non-RT task while holding lock"},
	{test_fmlp_lock_mode_change, "FMLP task becomes non-RT task while holding lock"},
	{test_srp_lock_teardown, "SRP task exits while holding lock"},
	{test_fmlp_lock_teardown, "FMLP task exits while holding lock"},
	{test_dflp_lock_teardown, "DFLP task exits while holding lock"},
};
int LINUX_TESTS[] = {
	0,
	1,
	2,
	5,
	7,
	28,
	29,
	30,
};
#define NUM_LINUX_TESTS 8
int C_EDF_TESTS[] = {
	0,
	1,
	2,
	5,
	6,
	7,
	8,
	9,
	10,
	28,
	29,
	30,
	33,
	34,
};
#define NUM_C_EDF_TESTS 14
int P_FP_TESTS[] = {
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	14,
	15,
	16,
	17,
	20,
	21,
	22,
	23,
	24,
	25,
	26,
	27,
	29,
	30,
	32,
	33,
	34,
	35,
	36,
	37,
	39,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
	53,
	54,
	55,
	57,
	58,
	60,
	61,
};
#define NUM_P_FP_TESTS 51
int PFAIR_TESTS[] = {
	0,
	1,
	2,
	5,
	6,
	7,
	8,
	9,
	10,
	28,
	29,
	30,
	33,
	34,
};
#define NUM_PFAIR_TESTS 14
int GSN_EDF_TESTS[] = {
	0,
	1,
	2,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	29,
	30,
	31,
	33,
	34,
	50,
	53,
	58,
	60,
};
#define NUM_GSN_EDF_TESTS 19
int PSN_EDF_TESTS[] = {
	0,
	1,
	2,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	29,
	30,
	31,
	32,
	33,
	34,
	50,
	53,
	58,
	60,
};
#define NUM_PSN_EDF_TESTS 20
struct testsuite testsuite[] = {
	{"LINUX", LINUX_TESTS, NUM_LINUX_TESTS},
	{"C-EDF", C_EDF_TESTS, NUM_C_EDF_TESTS},
	{"P-FP", P_FP_TESTS, NUM_P_FP_TESTS},
	{"PFAIR", PFAIR_TESTS, NUM_PFAIR_TESTS},
	{"GSN-EDF", GSN_EDF_TESTS, NUM_GSN_EDF_TESTS},
	{"PSN-EDF", PSN_EDF_TESTS, NUM_PSN_EDF_TESTS},
};
#define NUM_PLUGINS 6
