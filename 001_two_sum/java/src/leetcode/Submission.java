package leetcode;

/**
 * Created by enduser on 8/12/2015.
 */
public class Submission {
  public int[] twoSum(int[] nums, int target) {
    int[][] numsIndexed = pairIndices(nums);
    numsIndexed = mergeSort(numsIndexed);
    return twoSum(numsIndexed, target);
  }

  public int[][] pairIndices(int[] nums) {
    int[][] valsAndIndices = new int[nums.length][2];
    for (int i = 0; i < nums.length; i++) {
      valsAndIndices[i][0] = nums[i];
      valsAndIndices[i][1] = i;
    }
    return valsAndIndices;
  }

  public int[] twoSum(int[][] valsAndIndices, int target) {
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

  public int[][] merge(int[][] a, int[][] b) {
    int length = a.length + b.length;
    int[][] merged = new int[length][2];

    int i = 0, j = 0;
    while ((i < a.length) && (j < b.length)) {
      boolean aLessThanB = a[i][0] < b[j][0];

      if (aLessThanB) {
        merged[i+j] = a[i];
        i++;
      } else {
        merged[i + j] = b[j];
        j++;
      }
    }

    if (i == a.length) {
      while (j < b.length) {
        merged[i+j] = b[j];
        j++;
      }
    }

    else {
      while (i < a.length) {
        merged[i+j] = a[i];
        i++;
      }
    }

    return merged;
  }

  public int[][] mergeSort(int[][] array) {
    if (array.length <= 1)
      return array;

    int middle = array.length / 2;

    int[][] left = new int[middle][2],
        right = new int[array.length - middle][2];

    for (int i = 0; i < middle; i++) {
      left[i] = array[i];
    }
    for (int i = middle; i < array.length; i++) {
      right[i-middle] = array[i];
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
  }
}