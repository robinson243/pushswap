#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

struct PeopleList
{
	int age;
	char *name;
	struct PeopleList *next;
};

struct PeopleList *createNode(int age, char *name)
{
	struct PeopleList *myList = malloc(sizeof(struct PeopleList));
	myList->age = age;
	myList->name = strdup(name);
	myList->next = NULL;

	return myList;
}

void pushFront(struct PeopleList **head, int age, char *name)
{
	struct PeopleList *newnode = createNode(age, name);

	newnode->next = *head;
	*head = newnode;
}

void printList(struct PeopleList *head)
{
	struct PeopleList *current = head;

	while (current)
	{
		printf("le nom %s et l'age %d \n", current->name, current->age);
		current = current->next;
	}
}

void pushBack(struct PeopleList **head, int age, char *name)
{
	struct PeopleList *current = *head;
	struct PeopleList *newNode = createNode(age, name);

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = newNode;
}

void popFront(struct PeopleList **head)
{
	if (*head == NULL)
		return;
	struct PeopleList *tmp = *head;
	*head = (*head)->next;
}
void popBack(struct PeopleList **head)
{
	if (*head == NULL)
		return;
	struct PeopleList *cur = *head;

	if ((*head)->next == NULL)
	{
		free((*head)->name);
		free(*head);
		*head = NULL;
	}

	while (cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next->name);
	free(cur->next);
	cur->next = NULL;
}

void insertAt(struct PeopleList **head, int pos, int age, char *name)
{
	if (pos < 0)
		return ;
	int	i = 0;
	struct PeopleList *current = *head;
	struct PeopleList *newNode = createNode(age, name);

	if (pos == 0)
		pushFront(head, age, name);
	
	while (current && i < pos -1)
	{
		current = current->next;
		i++;
	}
	if (!current)
	{
		free(newNode->name);
		free(newNode);
		return ;
	}
	newNode->next = current->next;
	current->next = newNode;	
}

void removeAt(struct PeopleList **head, int pos)
{
	if (pos < 0)
		return ;
	int	i = 0;
	struct PeopleList *current = *head;
	struct PeopleList *tmp;

	if (*head == NULL)
		return ;
	
	if (pos == 0)
		popFront(head);
	while (current && i < pos - 1)
	{
		current = current->next;
		i++;
	}
	tmp = current->next;
	current->next = current->next->next;
	free(tmp->name);
	free(tmp);
}

int main(void)
{
	struct PeopleList *myList;

	pushFront(&myList, 25, "Toto");
	pushFront(&myList, 5, "Tata");
	pushFront(&myList, 58, "Titi");

	pushBack(&myList, 60, "test");
	popBack(&myList);

	insertAt(&myList, 1, 27, "Jojo");

	removeAt(&myList, 1);

	printList(myList);
	return 0;
}

/*
le nom Titi et l'age 58
le nom Tata et l'age 5
le nom Toto et l'age 25
le nom test et l'age 60  */