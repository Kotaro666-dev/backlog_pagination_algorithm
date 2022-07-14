#include <stdio.h>
#include <stdlib.h>

#define MAX_DISPLAY_PAGES 9
#define CURRENT_PAGE_INDEX 1
#define LAST_PAGE_INDEX 2
#define TRUE 1
#define FALSE 0
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct s_pagination
{
	int	current_page;
	int	last_page;
	int	distance_to_first_page;
	int distance_to_last_page;
	int are_more_pages_in_front;
	int are_more_pages_behind;
	int pages[MAX_DISPLAY_PAGES + 1];
}				t_pagination;

void	initialize(t_pagination *pagination, char **argv)
{
	pagination->current_page = atoi(argv[CURRENT_PAGE_INDEX]);
	pagination->last_page = atoi(argv[LAST_PAGE_INDEX]);

	pagination->distance_to_first_page =
		pagination->current_page - 1;
	pagination->distance_to_last_page =
		pagination->last_page - pagination->current_page;

	pagination->are_more_pages_in_front = FALSE;
	pagination->are_more_pages_behind = FALSE;

	if (pagination->last_page > MAX_DISPLAY_PAGES &&
		pagination->distance_to_first_page > 4)
	{
		pagination->are_more_pages_in_front = TRUE;
	}
	if (pagination->last_page > MAX_DISPLAY_PAGES &&
		pagination->distance_to_last_page > 4)
	{
		pagination->are_more_pages_behind = TRUE;
	}
}

void	create_pages(t_pagination *pagination, int start_page, int end_page)
{
	int page = start_page;
	int i = 0;

	while (page <= end_page && i < MAX_DISPLAY_PAGES)
	{
		pagination->pages[i] = page;
		page++;
		i++;
	}
}

void	display_pages(t_pagination *pagination)
{
	if (pagination->are_more_pages_in_front)
	{
		printf("... ");
	}
	int i = 0;
	while (i < MAX_DISPLAY_PAGES)
	{
		int has_no_more_pages = pagination->pages[i] == 0;
		if (has_no_more_pages)
		{
			break;
		}
		printf("%d ", pagination->pages[i]);
		i++;
	}
	if (pagination->are_more_pages_behind)
	{
		printf("...");
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	t_pagination pagination;

	if (argc != 3)
	{
		printf("コマンドライン引数の数があっていません\n");
		return (1);
	}

	initialize(&pagination, argv);
	if (pagination.last_page < MAX_DISPLAY_PAGES + 1)
	{
		create_pages(&pagination, 1, pagination.last_page);
	}
	else if (pagination.are_more_pages_in_front && pagination.are_more_pages_behind)
	{
		int start_page = pagination.current_page - 4;
		int last_page = pagination.current_page + 4;
		create_pages(&pagination, start_page, last_page);
	}
	else if (pagination.are_more_pages_in_front && !pagination.are_more_pages_behind)
	{
		int start_page = pagination.last_page - (MAX_DISPLAY_PAGES - 1);
		int last_page = pagination.last_page;
		create_pages(&pagination, start_page, last_page);
	}
	else if (!pagination.are_more_pages_in_front && pagination.are_more_pages_behind)
	{
		int start_page = 1;
		int last_page = max(pagination.current_page + 4, pagination.last_page);
		create_pages(&pagination, start_page, last_page);
	}
	display_pages(&pagination);
	return (0);
}
