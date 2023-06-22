/*
 * File: main_monty.c
 * Auth: Sess254
 */

#include "monty.h"

vars *first;

/**
 * main - main
 * description: main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int main(int argc, char **argv)
{
	first = malloc(sizeof(vars));
	if (!first)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	first->n = 0;
	first->error_code = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opcode_loop(argv);
	return (0);
}

/**
 * opcode_loop - interpreter
 * description: this takes input
 * @argv: argv
 * Return: 0
 */

int opcode_loop(char **argv)
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int characters, i, err;
	char *linebuff = NULL;
	size_t buffsize;
	FILE *fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(first);
		exit(EXIT_FAILURE);
	}
	characters = _getline(&linebuff, &buffsize, fp);
	while (characters >= 0)
	{
		for (i = 0; linebuff[i] != '\0'; i++)
		{
			if (linebuff[i] == '\n' && linebuff[i + 1] == '\0')
				linebuff[i] = '\0';
		}
		line_number++;
		tokenize(&stack, linebuff, line_number);
		if (linebuff != NULL)
			free(linebuff);
		linebuff = NULL;
		if (first->error_code == -1)
			break;
		characters = _getline(&linebuff, &buffsize, fp);
	}
	err = first->error_code;
	fclose(fp);
	if (linebuff != NULL)
		free(linebuff);
	free_stack(stack);
	free(first);
	if (err == -1)
		exit(EXIT_FAILURE);
	return (0);
}

/**
 * tokenize - tokenize
 * description: tokenize
 * @line: line
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: 0
 */

int tokenize(stack_t **stack, char *line, unsigned int line_number)
{
	char *linebuff = NULL, *nbuff = NULL;
	int b = 0;

	linebuff = strtok(line, " ");
	if (!linebuff)
	{
		return (0);
	}
	nbuff = linebuff;
	nbuff = strtok(NULL, " ");
	if (nbuff != NULL)
	{
		first->n = atoi(nbuff);
		b = opcode_find(stack, linebuff, line_number);
	}
	else if (b != 1)
	{
		if (strcmp(linebuff, "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			first->error_code = -1;
			return (-1);
		}
			b = opcode_find(stack, linebuff, line_number);
	}
	return (1);
}


/**
 * opcode_find - finds proper opcode
 * description: str compares opcode for correlating func
 * @stack: dbl ptr to stack
 * @linebuff: linebuff
 * @line_number: ln count for errors
 * Return: 0 or 1
 */


int opcode_find(stack_t **stack, char *linebuff, unsigned int line_number)
{
	int i;

	instruction_t arr[] = {
		{"push", m_push}, {"pall", m_pall},
		{"pint", m_pint}, {"pop", m_pop},
		{"swap", m_swap}, {"add", m_add},
		{"nop", m_nope}, {"sub", m_sub},
		{"div", m_div}, {"mul", m_mull},
		{"mod", m_mod},	{"#", m_nope},
		{"pchar", m_pchar}, {"pstr", m_pstr},
		{"rotl", m_rotl}, {"rotr", m_rotr},
		{"\0", NULL}
	};

	if (linebuff != NULL)
	{
		for (i = 0; arr[i].f; i++)
		{
			if (strcmp(linebuff, arr[i].opcode) == 0)
			{
				arr[i].f(stack, line_number);
				return (1);
			}
			else if (linebuff[0] == '#')
			{
				arr[11].f(stack, line_number);
				return (1);
			}
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, linebuff);
	first->error_code = -1;
	return (-1);
}
