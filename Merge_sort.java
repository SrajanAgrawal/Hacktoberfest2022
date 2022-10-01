import java.util.*;

public class Merge_sort {
    public static void main(String[] args) throws Exception {
        /**
         * Merge sort
         */
        sort(new int[] { 4, 1, 5, 8, 9, 3 });
    }

    static void sort(int[] array) {
        if (array.length < 2)
            return;
        int middle = array.length / 2;
        int[] left = new int[middle];
        int[] right = new int[array.length - middle];

        for (int i = 0; i < left.length; i++)
            left[i] = array[i];

        for (int i = middle; i < array.length; i++)
            right[i - middle] = array[i];

        sort(left);
        sort(right);

        merge(left, right, array);

    }

    static void merge(int[] left, int[] right, int[] array) {
        int i = 0, j = 0, k = 0;

        while (i < left.length && j < right.length)
            if (left[i] <= right[j])
                array[k++] = left[i++];
            else
                array[k++] = right[j++];

        while (i < left.length)
            array[k++] = left[i++];

        while (j < right.length)
            array[k++] = right[j++];

    }
}
