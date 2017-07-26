public int bucketFromRandom(int randomNumber) {
	int a[]	= new int[10];
	for (int i = 0; i < a.length; i++)
		a[i] = i * randomNumber;
	int index = Math.abs(randomNumber) % a.length;
	return a[index];
}

