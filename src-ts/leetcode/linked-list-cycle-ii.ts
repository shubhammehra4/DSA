/**
 * Definition for singly-linked list.
 */
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function detectCycle(head: ListNode | null): ListNode | null {
  if (!head || !head.next) return null;

  let fast = head.next.next;
  let slow = head.next;

  while (fast && fast.next && fast !== slow) {
    fast = fast.next.next;
    slow = slow.next;
  }

  if (!fast || !fast.next) return null;

  fast = head;
  while (fast !== slow) {
    fast = fast.next;
    slow = slow.next;
  }

  return slow;
}

// Hasp Map
function detectCycleH(head: ListNode | null): ListNode | null {
  if (!head || !head.next) return null;

  const listSet = new Set<ListNode>();
  let curr = head;

  while (curr) {
    if (listSet.has(curr)) return curr;

    listSet.add(curr);
    curr = curr.next;
  }

  return null;
}
