#include <project.h>
#include "twl_graph.h"

static void simple_test(t_test *test)
{
	t_graph_node			*node0;
	t_graph_node			*node1;
	t_graph_node			*node2;
	t_graph_node			*node3;

	node0 = twl_graph_node_new(0, "A");
	node1 = twl_graph_node_new(1, "B");
	node2 = twl_graph_node_new(2, "C");
	node3 = twl_graph_node_new(3, "D");

	mt_assert(strcmp(node0->data_, "A") == 0);
	mt_assert(strcmp(node1->data_, "B") == 0);
	mt_assert(strcmp(node2->data_, "C") == 0);
	mt_assert(strcmp(node3->data_, "D") == 0);
	mt_assert(twl_lst_len(node0->links_) == 0);
	mt_assert(twl_lst_len(node1->links_) == 0);
	mt_assert(twl_lst_len(node2->links_) == 0);
	mt_assert(twl_lst_len(node3->links_) == 0);
	mt_assert(!node0->is_visited_);
	mt_assert(!node1->is_visited_);
	mt_assert(!node2->is_visited_);
	mt_assert(!node3->is_visited_);
}

void	suite_twl_graph_node_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
