package leetcode;

public class Main {

    public static void main(String[] args) {
        ListNode a_0 = new ListNode(2);
        ListNode a_1 = new ListNode(4);
        ListNode a_2 = new ListNode(5);

        a_0.next = a_1;
        a_1.next = a_2;

        ListNode b_0 = new ListNode(5);
        ListNode b_1 = new ListNode(6);
        ListNode b_2 = new ListNode(4);

        b_0.next = b_1;
        b_1.next = b_2;

        ListNode answer = new ListNode(7);
        answer.next = new ListNode(0);
        answer.next.next = new ListNode(0);
        answer.next.next.next = new ListNode(1);

        Solution solver = new Solution();
        ListNode computedAnswer = solver.addTwoNumbers(a_0, b_0);

        int check = 0;
    }
}
