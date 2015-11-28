#include <project.h>

#include "twl_mlx_img.h"

static void test_simple(t_test *test)
{
	void 			*mlx;
	t_twl_mlx_img	*img;

	img = NULL;
	mlx = mlx_init();
	img = twl_mlx_img_new(mlx, 42, 12);
	mt_assert(img != NULL);
	mt_assert(img->img_ptr != NULL && img->img_data != NULL);
	mt_assert(img->img_ptr != NULL && img->img_data != NULL);
	mt_assert(img->width == 42 && img->height != 21);
}

void	suite_twl_mlx_img_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
