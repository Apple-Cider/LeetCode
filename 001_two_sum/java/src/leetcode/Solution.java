package leetcode;

/**
 * Created by enduser on 8/12/2015.
 */
public class Solution {
    public static int[] twoSum(int[] nums, int target) {
      int[][] numsIndexed = pairIndices(nums);
      numsIndexed = Merge.mergeSort(numsIndexed);
      return twoSum(numsIndexed, target);
    }

  /**
   * Pairs array of numbers with their indices.
   *
   * @param nums array of integers
   * @return 2D array where first val is the num, second is the index
   */
  public static int[][] pairIndices(int[] nums) {
    int[][] valsAndIndices = new int[nums.length][2];
    for (int i = 0; i < nums.length; i++) {
      valsAndIndices[i][0] = nums[i];
      valsAndIndices[i][1] = i;
    }
    return valsAndIndices;
  }

  /**
   *
   *
   * @param valsAndIndices
   * @param target
   * @return
   */
  public static int[] twoSum(int[][] valsAndIndices, int target) {
    int i = 0, j = valsAndIndices.length-1, min, max, sum;

    do {
      min = valsAndIndices[i][0];
      max = valsAndIndices[j][0];
      sum = min + max;
      if (sum < target) i++;
      if (sum > target) j--;
    } while (sum != target);

    int firstIdx = valsAndIndices[i][1],
      secondIdx = valsAndIndices[j][1];
    //in event addends are same, indicies may be out of order
    if (firstIdx > secondIdx) {
      int tmp = firstIdx;
      firstIdx = secondIdx;
      secondIdx = tmp;
    }
    //offset zero-based indices
    int[] answer = { firstIdx + 1, secondIdx + 1};
    return answer;
  }
}
