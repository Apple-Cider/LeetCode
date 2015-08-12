package leetcode;

/**
 * Created by enduser on 8/12/2015.
 */
public class Solution {
  public ListNode sum(ListNode node, int carry) {
    if (carry == 0) {
      return node;
    }
    if (node == null) {
      return new ListNode(carry);
    }

    int sum = node.val + carry;
    int ones = sum % 10,
        tens = sum / 10;
    ListNode result = new ListNode(ones);
    result.next = sum(node.next, tens);
    return result;
  }

  public ListNode sum(ListNode left, ListNode right, int carry) {
    if (left == null) {
      if (right == null) {
        if (carry == 0)
          return null;
        else
          return new ListNode(carry);
      }
      else
        return sum(right, carry);
    }

    if (right == null)
      return sum(left, carry);

    int sum = left.val + right.val + carry;
    int ones = sum % 10,
        tens = sum / 10;
    ListNode result = new ListNode(ones);
    result.next = sum(left.next, right.next, tens);
    return result;
  }

  public ListNode addTwoNumbers(ListNode left, ListNode right) {
    return sum(left, right, 0);
  }
}
