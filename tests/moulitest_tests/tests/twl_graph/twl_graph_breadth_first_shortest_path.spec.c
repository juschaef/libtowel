#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));
	t_graph_node_id nodeC_id = twl_graph_add_node(graph, strdup("C"));
	t_graph_node_id nodeD_id = twl_graph_add_node(graph, strdup("D"));
	t_graph_node_id nodeE_id = twl_graph_add_node(graph, strdup("E"));

	t_graph_node_id nodeF_id = twl_graph_add_node(graph, strdup("F"));
	t_graph_node_id nodeZ_id = twl_graph_add_node(graph, strdup("Z"));

	twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);
	twl_graph_add_edge(graph, nodeB_id, nodeC_id, NULL);
	twl_graph_add_edge(graph, nodeC_id, nodeD_id, NULL);
	twl_graph_add_edge(graph, nodeD_id, nodeZ_id, NULL);

	twl_graph_add_edge(graph, nodeA_id, nodeE_id, NULL);
	twl_graph_add_edge(graph, nodeE_id, nodeF_id, NULL);
	twl_graph_add_edge(graph, nodeF_id, nodeZ_id, NULL);
	t_lst			*solution = twl_graph_breadth_first_shortest_path(graph, nodeA_id, nodeZ_id);
	mt_assert(strcmp(twl_lst_get(solution, 0), "A") == 0);
	mt_assert(strcmp(twl_lst_get(solution, 1), "E") == 0);
	mt_assert(strcmp(twl_lst_get(solution, 2), "F") == 0);
	mt_assert(strcmp(twl_lst_get(solution, 3), "Z") == 0);
}

static void test_simple_path(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));
	t_graph_node_id nodeZ_id = twl_graph_add_node(graph, strdup("Z"));
	t_graph_node_id nodeF_id = twl_graph_add_node(graph, strdup("F"));

	twl_graph_add_edge(graph, nodeA_id, nodeB_id, NULL);
	twl_graph_add_edge(graph, nodeB_id, nodeZ_id, NULL);
	twl_graph_add_edge(graph, nodeA_id, nodeF_id, NULL);

	t_lst			*solution = twl_graph_breadth_first_shortest_path(graph, nodeA_id, nodeZ_id);
	mt_assert(strcmp(twl_lst_get(solution, 0), "A") == 0);
	mt_assert(strcmp(twl_lst_get(solution, 1), "B") == 0);
	mt_assert(strcmp(twl_lst_get(solution, 2), "Z") == 0);
}

static void test_not_found(t_test *test)
{
	t_graph *graph = twl_graph_new();
	t_graph_node_id nodeA_id = twl_graph_add_node(graph, strdup("A"));
	t_graph_node_id nodeB_id = twl_graph_add_node(graph, strdup("B"));
	t_graph_node_id nodeC_id = twl_graph_add_node(graph, strdup("C"));

	t_lst			*solution = twl_graph_breadth_first_shortest_path(graph, nodeA_id, nodeC_id);
	mt_assert(solution == NULL);
	(void)nodeB_id;
}

void	suite_twl_graph_breadth_first_shortest_path(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, test_simple_path);
	SUITE_ADD_TEST(suite, test_not_found);
}
