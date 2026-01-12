# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node   *previous;
} t_node;

typedef struct s_stack
{
	t_node  *head; // top
	t_node  *tail; // bottom
} t_stack;


t_stack		ft_stack_new(void)
{
	t_stack		rt_stack;

	rt_stack = *(t_stack *)(malloc(sizeof(t_stack)));
	rt_stack.head = NULL;
	rt_stack.tail = NULL;
	return (rt_stack);
}

int		ft_stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)(malloc(sizeof(t_node)));
	new_node->value = value;
	new_node->next = NULL;
	if (! stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->previous = stack->head;
		stack->head->next = new_node;
		stack->head = new_node;
	}
	return (value);
}

t_node	*ft_stack_pop(t_stack *stack)
{
	t_node	*rt_node;
	t_node	*new_head;

	rt_node = (t_node *)(malloc(sizeof(t_node)));
	new_head = (t_node *)(malloc(sizeof(t_node)));
	rt_node = stack->head;
	new_head = rt_node->previous;
	new_head->next = NULL;
	stack->head = new_head;
	return (rt_node);
}

t_node	*ft_stack_peek_head_node(t_stack *stack)
{
	return (stack->head);
}

t_node	*ft_stack_peek_tail_node(t_stack *stack)
{
	return (stack->tail);
}

int		ft_stack_peek_head_value(t_stack *stack)
{
	return (stack->head->value);
}

int		ft_stack_peek_tail_value(t_stack *stack)
{
	return (stack->tail->value);
}

int		ft_stack_size(t_stack *stack)
{
	t_node	*current;
	int		rt_length;

	current = (t_node *)(malloc(sizeof(t_node)));
	current = stack->tail;
	rt_length = 0;
	while (current)
	{
		rt_length++;
		current = current->next;
	}
	return (rt_length);
}

void	ft_stack_print_bottom_up(t_stack *stack)
{
	t_node	*current;

	current = (t_node *)(malloc(sizeof(t_node)));
	current = stack->tail;
	while (current)
	{
		printf("%d", current->value);
		current = current->next;
		if (current)
			printf("->");
	}
	printf("\n");
}

void	ft_stack_print_top_down(t_stack *stack)
{
	t_node	*current;

	current = (t_node *)(malloc(sizeof(t_node)));
	current = stack->head;
	while (current)
	{
		printf("%d", current->value);
		current = current->previous;
		if (current)
			printf("<-");
	}
	printf("\n");
}


int main()
{
	t_stack my_stack = ft_stack_new();
	ft_stack_print_bottom_up(&my_stack);
	ft_stack_push(&my_stack, 1);
	ft_stack_print_bottom_up(&my_stack);
	ft_stack_push(&my_stack, 4);
	ft_stack_push(&my_stack, 6);
	ft_stack_print_bottom_up(&my_stack);
	ft_stack_print_top_down(&my_stack);
	printf("%d\n", ft_stack_size(&my_stack));
	ft_stack_pop(&my_stack);
	ft_stack_print_bottom_up(&my_stack);
	ft_stack_print_top_down(&my_stack);
}