# 0x17. Find the Loop

## About
Function that finds the loop in a linked list

`listint_t *find_listint_loop(listint_t *head);`

```
/**
 * struct listint_s - singly linked list  
 * @n: integer  
 * @next: points to the next node  
 *  
 * Description: singly linked list node structure  
 * for Holberton project  
 */  
typedef struct listint_s  
{  
    int n;  
    struct listint_s *next;  
} listint_t;  
```

### Author
Thomas Graeff
