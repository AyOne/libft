/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 03:37:18 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 03:37:37 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	constructor(void) __attribute__((constructor));
void	destructor(void) __attribute__((destructor));

typedef struct container {
	int *a;
	int *b;
} container;


container *static_getter(void)
{
	static container c;
	return &c;
}



int main(void)
{
	printf("Main\n");
	container *c = static_getter();
	printf("a: %d, b: %d\n", *c->a, *c->b);
	int a = strlen((const char*)0x27562785);
	return 0;
}


void constructor(void)
{
	printf("Constructor\n");
	container *c = static_getter();
	c->a = (int *)malloc(sizeof(int));
	c->b = (int *)malloc(sizeof(int));
	if (c->a == NULL || c->b == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	*c->a = 10;
	*c->b = 20;
	printf("a: %d, b: %d\n", *c->a, *c->b);
}

void destructor(void)
{
	printf("Destructor\n");
	container *c = static_getter();
	free(c->a);
	free(c->b);
}