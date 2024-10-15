//		ArrayList.c

// Implementation of a static list using arrays
// We will use array of integers for simplicity
// We can use an array of any type including array of structures

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE	100


// Create a list of a given number of elements
void CreateList (int *cur_max, int list[])
{
	printf ("Enter the number of elements to be added in the list:\t");
	scanf ("%d", cur_max);
	printf ("Enter the array elements:\t");
	for (int i = 0;i < *cur_max; i++)
		scanf ("%d", &list[i]);
}

bool IsListEmpty (int cur_max)
{
	bool ret_val = false;
	if (cur_max == 0)
		ret_val = true;
	return ret_val;
}


// Insert an element into the list
bool Insert(int *cur_max, int list[])
{
	int data, pos;
	
	printf ("Enter the data to be inserted:");
	scanf ("%d", &data);
	printf ("Enter the position at which element has to be inserted:");
	scanf ("%d", &pos);
	if (pos >= MAX_SIZE || pos < 0)
	{
		printf ("Invalid position");
		return false;
	}
	if (pos > (*cur_max + 1))	// preventing empty spaces
		pos = *cur_max + 1;
	for(int i = *cur_max - 1 ; i >= pos - 1 ; i--)
		list [i + 1] = list [i];

	list [pos - 1] = data;
	*cur_max = *cur_max + 1;
	return true;;
}

// The deletion operation
void Delete (int *cur_max, int list[])
{
	int i, pos ;
 	printf ("\nEnter the position of the data to be deleted:\t");
	scanf ("%d", &pos);
	
	if (pos < 0)
	{
		printf ("Invalid position\n");
		return;
	}
	if (pos <= *cur_max)
	{
		printf ("The data deleted is: %d\n", list[pos-1]);
		for (i = pos - 1;i < *cur_max - 1; i ++)
			list [i] = list[i + 1];
		*cur_max = *cur_max - 1;
	}
	else
		printf ("There is no valid data at that position\n");
}

void Modify (int *cur_max, int list[])
{
	int pos, newVal;

	printf ("The position of the element to be modified:");
	scanf ("%d", &pos);
	if (pos < 0)
	{
		printf ("Invalid position\n");
		return;
	}

	if (pos <= *cur_max)
	{
		printf ("Key in the new value:");
		scanf ("%d", &newVal);
		list [pos - 1] = newVal;
	}
	else
		printf ("There is no data at that position\n");
}


// Display the values of the elements in the array
void Display(int *cur_max, int list[])
{
	int i;
	printf("\n**********Elements in the array**********\n");
	for (i = 0;i < *cur_max; i++)
		printf ("%d\t", list[i]);
	printf ("\n");
}

// Search for an element in the list
void Search(int *cur_max, int list[])
{
	int search;
	bool found = false;
	printf("\nEnter the element to be searched:\t");
	scanf ("%d", &search);
	for (int i = 0;i < *cur_max; i++)
	{
 		if(search == list[i])
		{
			found = true;
			break;
		}
	}
	found == true ? printf("\nElement present in the list\n"):
			printf("\nElement not present in the list\n");
}

