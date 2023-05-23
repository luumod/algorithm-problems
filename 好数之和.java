import java.util.Scanner;
public class 好数之和 {
    public static void main(String[] args) {
        new 好数之和().go();
    }
    public void go() {
        try (Scanner sc = new Scanner(System.in)) {
            int l = sc.nextInt(), r = sc.nextInt();
            System.out.println(dfs(r) - dfs(l - 1));
        }
    }
    public long dfs(int num) {
        if(num < 2022) return 0;
        int n = getLength(num), x = 2022, y = 10000, z = 1;
        long res = 0;
        for(int i = 0; i < n - 3; i++) {
            int prefix = num / y;
            for(int j = 0; j < prefix; j++) {
                for(int k = 0; k < z; k++) {
                    long m = (long) j * y + x + k;
                    // ȥ�ز�������Ϊ��12022022����������2022�ģ�ֻ�ܼ���һ�Σ������Ҫ��֤β��������2022
                    res += isValid(m % (z * 1000L)) ? 0 : m;
                }
            }
            // �ж��ٽ����
            int flag = (num / z) % 10000;
            int up = flag == 2022 ? num % z + 1 : flag < 2022 ? 0 : z;
            for(int j = 0; j < up; j++) {
                long m = (long) prefix * y + x + j;
                // ȥ�ز�������Ϊ��12022022����������2022�ģ�ֻ�ܼ���һ�Σ������Ҫ��֤β��������2022
                res += isValid(m % (z * 1000L)) ? 0 : m;
            }
            y *= 10; x *= 10; z *= 10;
        }
        return res;
    }
    public boolean isValid(long x) {
        String s = String.valueOf(x);
        return s.contains("2022");
    }
    public int getLength(int x) {
        int res = 0;
        while (x != 0) {
            res++;
            x /= 10;
        }
        return res;
    }
}
