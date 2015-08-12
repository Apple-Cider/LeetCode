package leetcode;

/**
 *
 */
public class Main {

    public static void main(String[] args) {
      //int[] myArray = { 7, 5, 6, 2, 8, 0, 1, 4, 9, 3 };
      int[] myArray = { 11, 14, 6, 8, 4, 3, 9, 0, -2, 1};

      int target = 13;

      int[] answer = { 5 , 7 };

      //int[] computedAnswer = Solution.twoSum(myArray, target);
      Submission submitter = new Submission();
      int[] computedAnswer = submitter.twoSum(myArray, target);
      int[] otherArray = {0, 4, 3, 0};
      int[] otherAnswer = submitter.twoSum(otherArray, 0);
      //int[][] myArrayIndexed = Solution.pairIndices(myArray);

      //myArrayIndexed = Merge.mergeSort(myArrayIndexed);

      int hope = 3;

    }
}