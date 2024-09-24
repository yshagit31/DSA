// link - https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1?page=2&category=Recursion&sortBy=submissions
// You are given two linked lists representing two large positive numbers. The linked lists represent these two numbers, subtract the smaller number from the larger one and return the head of the linked list representing the result. Please take a look at the examples to get a better understanding of the task.

// Linked list does not contain leading zeros, except for the number zero itself.
// Examples:

// Input: LinkedList1: 1->0->0, LinkedList2: 1->2
// Output:  LinkedList: 8->8
// Explanation: First linked list represents 100 and the second one represents 12. 12 subtracted from 100 gives us 88 as the result. It is represented as 8->8 in the linked list.

// Input: LinkedList1: 6->3, LinkedList2: 7->1->0
// Output: LinkedList: 6->4->7
// Explanation: First linked list represents 63 and the second one represents 710. 63 subtracted from 710 gives us 647 as the result. It is represented as 6->4->7 in the linked list.

// Expected Time Complexity:  O(n+m)
// Expected Space Complexity: O(n+m)

// Constraints:
// 1 <= size of both linked lists <= 106
// 0 <= node->data <= 9

