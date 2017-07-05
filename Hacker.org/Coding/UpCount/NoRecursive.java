public class NoRecursive {
	private long calc(int depth) {
		if (depth == 0) return 1;
		long cc = calc(depth - 1);
		return cc + (depth % 7) + ((((cc ^ depth) % 4) == 0) ? 1 : 0); 
	}
	public static void main(String[] args) {
        long count[] = new long[11590];
        count[0] = 1;
        for (int i = 1; i != 11590; ++i) {
            long previous = count[i - 1];
            previous = (((count[i - 1] ^ i) & 3) == 0) ? 1 : 0;
            count[i] = count[i - 1] + i % 7 + previous;
        }
        System.out.println(count[11589]);
	}
}

