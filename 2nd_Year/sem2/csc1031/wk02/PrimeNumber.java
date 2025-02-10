import java.util.Scanner;

public class PrimeNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int limit = scanner.nextInt();

	int count = isPrime(limit, 0);

        System.out.println(count);
    }

    private static int isPrime(int num, int cnt) {
        boolean prime[] = new boolean[num + 1];
        for (int i = 0; i <= num; i++)
            prime[i] = true;

        for (int p = 2; p * p <= num; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= num; i += p)
                    prime[i] = false;
            }
        }

        for (int i = 2; i <= num; i++) {
            if (prime[i] == true)
                cnt++;
        }
	return cnt;	
    }
}
