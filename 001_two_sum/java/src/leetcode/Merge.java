package leetcode;

/**
 * Created by enduser on 8/12/2015.
 */
public class Merge {

  /**
   *
   * @param a 2D array sorted on first val
   * @param b 2D array sorted on first val
   * @return sorted merger of a and b, based on their first vals
   */
  public static int[][] merge(int[][] a, int[][] b) {
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

  /**
   *
   * @param array 2D array where first val is a num, second is its original index
   * @return array sorted based on its first vals
   */
  public static int[][] mergeSort(int[][] array) {
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
