//program to implement a double linked list
//made in c
//uses dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>
typedef struct s
{
	int info;
	struct s *prev, *next;
} node;

void create(node *s)
{
	char ans = 'y';
	int val;
	node *t;
	while (ans == 'y')
	{
		printf("Enter the value: ");
		scanf("%d", &val);
		s->info = val;
		printf("\nDo you want to add more nodes(y/n)?: ");
		scanf(" %c", &ans);
		if (ans == 'y')
		{
			t = s;
			s->next = (node *)malloc(sizeof(node));
			s = s->next;
			s->prev = t;
		}
		else
		{
			s->next = NULL;
		}
	}
}
void print(node *s)
{
	while (s != NULL)
	{
		printf("\nElement is %d", s->info);
		s = s->next;
	}
}
int count(node *s)
{
	int i = 0;
	while (s != NULL)
	{
		i++;
		s = s->next;
	}
	return (i);
}

node *insert(node *s)
{
	node *u = s, *p, *t;
	int pos, i, val;
	t = (node *)malloc(sizeof(node));
	if (t == NULL)
	{
		printf("Overflow");
	}
	else
	{
		printf("Enter value to be inserted: ");
		scanf(" %d", &val);
		t->info = val;
		printf("Enter position of insert: ");
		scanf(" %d", &pos);
		if (pos == 1)
		{
			t->next = s;
			t->prev = NULL;
			s->prev = t;
			s = t;
			return (s);
		}
		if (pos > 1 && pos <= count(s))
		{
			while (i < pos)
			{
				p = s;
				s = s->next;
				i++;
			}
			p->next = t;
			t->prev = p;
			t->next = s;
			s->prev = t;
			return (u);
		}
		if (pos == (count(s) + 1))
		{
			while (s->next != NULL)
			{
				s = s->next;
			}
			s->next = t;
			t->next = NULL;
			t->prev = s;
			return (u);
		}
	}
}

node *delete_n(node *s)
{
	node *temp, *u = s, *r, *p;
	int pos, i = 1;
	printf("Enter the position at where to delete: ");
	scanf("%d", &pos);
	if (pos == 1)
	{
		temp = s;
		s = s->next;
		s->prev = NULL;
		free(temp);
		return (s);
	}
	if (pos == count(s))
	{
		while (s->next != NULL)
		{
			p = s;
			s = s->next;
		}
		free(s);
		p->next = NULL;
		return (u);
	}
	if (pos > 1 && pos < count(s))
	{
		while (i < pos)
		{
			p = s;
			s = s->next;
			i++;
		}
		p->next = s->next;
		temp = s;
		r = s->next;
		r->prev = p;
		free(temp);
		return (u);
	}
}

void reverse(node *s)
{
	node *p, *t = NULL;
	while (s != NULL)
	{
		p = s;
		s = s->next;
		p->next = t;
		p->prev = s;
		t = p;
	}
	print(t);
}

int main()
{
	int c;
	node *start = (node *)malloc(sizeof(node));
	start->prev = NULL;
	start->next = NULL;
	while (1)
	{
		int t;
		printf("\nMENU\n");
		printf("\n1 - create");
		printf("\n2 - print");
		printf("\n3 - count");
		printf("\n4 - insert");
		printf("\n5 - delete");
		printf("\n6 - reverse");
		printf("\n7 - exit");
		printf("\n\nEnter choice: ");
		scanf(" %d", &c);
		switch (c)
		{
		case 1:
			create(start);
			break;
		case 2:
			print(start);
			break;
		case 3:
			t = count(start);
			printf("\nCount is %d", t);
			break;
		case 4:
			start = insert(start);
			break;
		case 5:
			start = delete_n(start);
			break;
		case 6:
			reverse(start);
			break;
		default:
			exit(0);
			break;
		}
	}
}