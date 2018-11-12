package search;

public class BinarySearchMissing {
    // Pre: (a[i]>=a[i+1]) && (a.length >= 0)
    // Post: (a[
    static int iterative(int[] a, int x) {
        if (a.length == 0) {
            return -1;
        }
        int l = -1, r = a.length;
        // I: (r' == n) && (r' < n && a[r']<=x)
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (a[m] <= x) {
                r = m;
            } else {
                l = m;
            }
        }
        //l'+1 = r'
        if (r != a.length && a[r] == x) {
            //a[r] = x
            return r;
        } else {
            //a[r]<x
            return (-r - 1);
        }
    }

    // Pre: (a.length >= 0) && (l = -1..n) && (r = 0..n) && (l<=r)
    // I:
    static int recursive(int[] a, int x, int l, int r) {
        if (a.length == 0) {
            return -1;
        }
        if (l + 1 >= r) {
            if (r != a.length && a[r] == x) {
                //a[r] = x
                return r;
            } else {
                //a[r]<x
                return (-r - 1);
            }
        }

        int m = (l + r) / 2;
        if (a[m] <= x) {
            //a[l'] >= x >= a[m]
            return recursive(a, x, l, m);
        } else {
            //a[m] > x >= a[r']
            return recursive(a, x, m, r);
        }
    }

    public static void main(String[] args) {
        int n = args.length - 1;
        int x = Integer.parseInt(args[0]);

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(args[i + 1]);
        }
        int firstRes = recursive(a, x, -1, n);
        int secondRes = iterative(a, x);

        if (firstRes != secondRes) {
            System.exit(228);
        } else {
            System.out.println(firstRes);
        }
    }
}
