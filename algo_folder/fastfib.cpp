void mulmat2(int a[][2], int b[][2], int c[][2]){
	c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];

	c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];	
}

void mulmatcol(int a[][2], int b[2], int c[2]){
	c[0] = a[0][0]*b[0] + a[0][1]*b[1];
	c[1] = a[1][0]*b[0] + a[1][1]*b[1];	
}

void fastMatPower(int a[][2], int n, int ans[][2]){
	if(n==1){
		ans[0][0]=a[0][0];
		ans[0][1]=a[0][1];
		ans[1][0]=a[1][0];
		ans[1][1]=a[1][1];
	}else
	{
		int b[2][2];
		fastMatPower(a, n/2, b);

		if(n%2==0){
			mulmat2(b, b, ans);
		}else
		{
			int ans2[2][2];
			mulmat2(b, b, ans2);
			mulmat2(ans2, a, ans);
		}

	}
}

int fastFibonacci(int n){
	if(n==0 || n==1)
		return n;
	else{
		int mat[2][2] = {{0, 1}, {1, 1}};
		int ans[2][2];
		fastMatPower(mat, n, ans);

		int f01[] = {0, 1}, fn[2];
		mulmatcol(ans, f01, fn);
		return fn[0];
	}
}
