void factor(Long n) {
	//Si o si necesito recorer hasta n 
	for (int i = 2; i <= n; i++) {
		if (!spf[i]) {
			for (int j = i; j <= n; j += i) {
				// Si se quita el if entonces se guardara el factor primo 
				// mas grande del numero
				if (!spf[j]) spf[j] = i; 
			}
		}
	}
}

