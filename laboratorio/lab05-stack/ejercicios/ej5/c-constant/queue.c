#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct s_queue {
  unsigned int size; 
  struct s_node *first;
  struct s_node *last;
};

struct s_node {
  queue_elem elem;
  struct s_node *next;
};

static struct s_node *create_node(queue_elem e) {
  struct s_node *new_node = malloc(sizeof(struct s_node));
  assert(new_node != NULL);
  new_node->elem = e;
  new_node->next = NULL;
  return new_node;
}

static struct s_node *destroy_node(struct s_node *node) {
  node->next = NULL;
  free(node);
  node = NULL;
  return node;
}

static bool invrep(queue q) {
  return q != NULL && q->size == queue_size(q);
}

queue queue_empty(void) {
  queue q = malloc(sizeof(*q));
  q->size = 0;
  q->first = NULL;
  q->last = NULL;
  assert(invrep(q) && queue_is_empty(q));
  return q;
}

queue queue_enqueue(queue q, queue_elem e) { 
  assert(invrep(q));

  struct s_node *new_node = create_node(e);

  if (queue_is_empty(q)) {
    q->first = new_node;
    q->last = new_node;
  } else {
    q->last->next = new_node;
    q->last = new_node;
  }

  q->size++;
  assert(invrep(q) && !queue_is_empty(q));
  return q;
}

bool queue_is_empty(queue q) {
  assert(invrep(q)); // NOTE
  return q->first == NULL;
}

queue_elem queue_first(queue q) {
  assert(invrep(q) && !queue_is_empty(q));
  return q->first->elem;
}

unsigned int queue_size(queue q) {
  // assert(invrep(q));
  return q->size;
}

queue queue_dequeue(queue q) { 
  assert(invrep(q) && !queue_is_empty(q)); 

  destroy_node(q->last);

  q->size--;
  assert(invrep(q));
  return q;
}

void queue_dump(queue q, FILE *file) {
  file = file == NULL ? stdout : file;
  struct s_node *node = q->first;
  fprintf(file, "[ ");
  while (node != NULL) {
    fprintf(file, "%d", node->elem);
    node = node->next;
    if (node != NULL) {
      fprintf(file, ", ");
    }
  }
  fprintf(file, "]\n");
}

queue queue_destroy(queue q) {
  assert(invrep(q));
  struct s_node *node = q->first;
  while (node != NULL) {
    struct s_node *killme = node;
    node = node->next;
    killme = destroy_node(killme);
  }
  free(q);
  q = NULL;
  assert(q == NULL);
  return q;
}

queue queue_disscard(queue q, unsigned int n) {
  assert(q != NULL && n < queue_size(q));

  struct s_node *p = q->first;

  if (n == 0) {
    q->first = q->first->next;
    free(p);
    p = q->first;
  }

  else if (n > 0) {
    for (unsigned int i = 0; i < n - 1; i++) {
      p = p->next;
    }
    struct s_node *killme = p->next;
    p->next = killme->next;
    destroy_node(killme);
  }

  q->size--;
  assert(q != NULL);
  return q;
}