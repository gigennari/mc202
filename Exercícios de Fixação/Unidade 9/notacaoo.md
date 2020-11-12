# Notação O


* ordem 
**O(1) < O(log n) < O(log^2 n) < O(n) < O(n log n) < O(n^2) < O(n^3) < O(2^n)**


* n^5 + 100000
    - vai demorar 100000 independentemente de n
    - então a notação é **O(n^5)**  

* log_35(n^n)
    - n * log_35(n)
    - então a notação é **O(n lg(n))**

* 2^(n-0,1)
    - para n suficientemente grandes, o 0,1 não muda muito o resultado
    - então a notação é **O(2^n)**

* 2^log(n^2)
    - = 2^(2*log2(n)) = (2^log2(n))^2 = (n)^2
    - então a notação é **O(n^2)**

* 1000^1000n + n^n
    - igualamos as duas parcelas e aplicamos log10 para encontrar n suficientemente grande e ver qual será a complexidade
    - log10(1000^1000n) = log(n^n)
    - 1000n * 3 = n log(n)
    - 3000 = log(n)
    - n = 10^3000
    - como O(n) > O(n)
