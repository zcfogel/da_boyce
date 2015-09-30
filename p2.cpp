#include "recursive.h"

/*
 * Effects: Returns the sum of each element in the list
 */
static int sum_helper(list_t list, int result)
{
	if (list_isEmpty(list)) return result;

	return sum_helper(list_rest(list), list_first(list) + result);
}

/*
 * EFFECTS: returns the sum of each element in list
 *          zero if the list is empty.
 */
int sum(list_t list)
{
	return sum_helper(list, 0);
}

/*
 * Effects: Returns the product of each element in list, product helper function
 */

static int product_helper(list_t list, int result)
{
	if (list_isEmpty(list)) return result;

	return sum_helper(list_rest(list), list_first(list) * result);
}

/*
 * EFFECTS: returns the product of each element in list
 *          one if the list is empty.
 */
int product(list_t list)
{
	return product_helper(list, 1);
}

/*
 * REQUIRES: fn must be associative.
 * EFFECTS:  return identity if list is empty.
 *           Otherwise, return the tail recursive equivalent of
 *           fn(list_first(list), accumulate(list_rest(list), fn, identity).
 *           Be sure to make your code tail-recursive!
 *
 * For example, if you have the following function:
 *
 *           int add(int x, int y);
 *
 * Then the following invocation returns the sum of all elements:
 *
 *           accumulate(list, add, 0);
 *
 * The "identity" argument is typically the value for which
 * fn(X, identity) == X and fn(identity, X) == X for any X.
 */
static int accumulate_helper(list_t list, int (*fn)(int, int), int identity, int total)
{
	if (list_isEmpty(list)) return total;
	return accumulate_helper(list_rest(list), fn, identity, fn(list_first(list),total));
}
int accumulate(list_t list, int (*fn)(int, int), int identity)

{
	if (list_isEmpty(list)) return identity;
	int total = identity;
	return accumulate_helper(list_rest(list), fn, identity, fn(list_first (list), total));
}

/*
 * EFFECTS: returns the reverse of list
 *
 * For example: the reverse of ( 3 2 1 ) is ( 1 2 3 )
 */
static list_t reverse_helper(list_t list, list_t temp)
{
	if (list_isEmpty (list))
	{
		return temp;
	}
	list_make (list_first(list), temp);
	return reverse_helper (list_rest (list), temp);
}
list_t reverse(list_t list)
{
	list_t temp = list_make();
	return reverse_helper (list, temp);

}

/*
 * EFFECTS: returns the list (first second)
 */
static list_t append_helper(list_t first, list_t second)
{
	if (list_isEmpty (first))
	{
		return second;
	}
	list_make (list_first (first), second);
	return append_helper (list_rest(first), second);
}
list_t append(list_t first, list_t second)
{
	return append_helper (reverse(first),second);
}

/*
 * EFFECTS: returns a new list containing only the elements of the
 *          original list which are odd in value,
 *          in the order in which they appeared in list.
 *
 * For example, if you applied filter_odd to the list ( 4 1 3 0 )
 * you would get the list ( 1 3 )
 */
 static list_t odd_helper(list_t list, list_t odd_list)
{
	if (list_isEmpty(list)) return reverse(odd_list);
	if (list_first(list) % 2 != 0) list_make(list_first(list), odd_list);
	return odd_helper(list_rest(list), odd_list);
}

list_t filter_odd(list_t list)
{
	list_t odd_list = list_make();
	return odd_helper(list, odd_list);
}

/*
 * EFFECTS: returns a new list containing only the elements of the
 *          original list which are even in value,
 *          in the order in which they appeared in list.
 *
 * For example, if you applied filter_odd to the list ( 4 1 3 0 )
 * you would get the list ( 4 0 )
 */
 static list_t even_helper(list_t list, list_t even_list)
{
	if (list_isEmpty(list)) return reverse(even_list);
	if (list_first(list) % 2 != 0) {list_make(list_first(list), even_list);}
	return even_helper(list_rest(list), even_list);
}

list_t filter_even(list_t list)
{
	list_t even_list = list_make();
	return even_helper(list, even_list);
}

/*
 * EFFECTS: returns a new list containing precisely the elements of list
 *          for which the predicate fn() evaluates to true, in the
 *          order in which  they appeared in list.
 */
 static list_t filter_helper(list_t list, list_t filter_list, bool (*fn)(int))
{
	if (list_isEmpty(list)) return reverse(filter_list);
	if ((*fn)(list_first(list)))
	{ 
		list_make(list_first(list), filter_list);
	}
	return filter_helper (list_rest(list), filter_list, fn);
}

list_t filter(list_t list, bool (*fn)(int))
{
	list_t filter_list = list_make();
	return filter_helper(list, filter_list, fn);
}

/*
 * REQUIRES: n >= 0
 *
 * EFFECTS: Returns a new list whose elements are in the order that would result
 *          from moving the front element of this list to the back,
 *          repeated n times.
 *
 *          For example, rotate(( 1, 2, 3, 4, 5 ), 2) yields ( 3, 4, 5, 1, 2 )
 *          For example, rotate(( 1, 2, 3 ), 7) yields ( 2, 3, 1 )
 */
list_t rotate(list_t list, int n);

/*
 * REQUIRES: n >= 0 and n <= the number of elements in first
 * EFFECTS: returns a list comprising the first n elements of
 *          "first", followed by all elements of "second",
 *           followed by any remaining elements of "first".
 *
 *     For example: insert (( 1 2 3 ), ( 4 5 6 ), 2)
 *            is  ( 1 2 4 5 6 3 ).
 */
list_t insert_list(list_t first, list_t second, int n);

/*
 * REQUIRES n >= 0 and list has at least n elements
 * EFFECTS: returns the list equal to list without its last n
 *          elements
 */


static int chop_help(list_t list, list_t chop_list, int say_when, int n)
{
	if (say_when == n) return reverse(chop_list);
	list_make(list_first(list), chop_list);
	++ say_when;
	return chop_help(list_rest(list), chop_list, say_when, n);
}

list_t chop(list_t list, int n)
{
	list_t chop_list = list_make();
	return chop_help(list, chop_list, 0, n);
}

/*
 * REQUIRES: n >= 0
 * EFFECTS: computes the Nth Fibonacci number
 *          fib(0) = 0
 *          fib(1) = 1
 *          fib(n) = fib(n-1) + fib(n-2) for (n>1).
 * This must be recursive but need not be tail recursive
 */





int fib(int n);

/*
 * REQUIRES: n >= 0
 * EFFECTS: computes the Nth Fibonacci number
 *          fib(0) = 0
 *          fib(1) = 1
 *          fib(n) = fib(n-1) + fib(n-2) for (n>1).
 * MUST be tail recursive
 * Hint: instead of starting at n and workind down, start at
 * 0 and 1 and *upwards*.
 */
int fib_tail(int n);

// EFFECTS: returns the sum of all elements in the tree,
//          zero if the tree is empty
int tree_sum(tree_t tree);

/* MODIFIES:
 * EFFECTS: returns the elements of tree in a list using an
 *          in-order traversal. An in-order traversal yields a list with
 *          the "left most" element first, then the second-left-most,
 *          and so on, with the right-most element last.
 *
 *          for example, the tree:
 *
 *                           4
 *                         /   \
 *                        /      \
 *                       2        5
 *                      / \      / \
 *                         3
 *                        / \
 *
 *  would return the list
 *
 *       ( 2 3 4 5 )
 *
 * An empty tree would print as:
 *
 *       ( )
 *
 */
list_t traversal(tree_t tree);

/*
 * EFFECTS: returns true if A is covered by B or if A is contained by either
 *          of B's subtrees.
 */
bool contained_by(tree_t A, tree_t B);

/*
 * REQUIRES; tree is a sorted binary tree
 * EFFECTS: returns a new tree with elt inserted at a leaf such that
 *          the resulting tree is also a sorted binary tree.
 *
 *          for example, inserting 1 into the tree:
 *
 *                           4
 *                         /   \
 *                        /      \
 *                       2        5
 *                      / \      / \
 *                         3
 *                        / \
 *
 * would yield
 *                           4
 *                         /   \
 *                        /      \
 *                       2        5
 *                      / \      / \
 *                     1   3
 *                    / \ / \
 *
 * Hint: an in-order traversal of a sorted binary tree is always a
 *       sorted list, and there is only one unique location for
 *       any element to be inserted.
 */
tree_t insert_tree(int elt, tree_t tree);