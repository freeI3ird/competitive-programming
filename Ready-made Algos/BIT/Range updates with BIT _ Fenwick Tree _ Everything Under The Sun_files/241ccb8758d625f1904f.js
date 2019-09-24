document.write('<link rel="stylesheet" href="https://assets-cdn.github.com/assets/gist-embed-08527ef2b62c06e4f818538458263d7d9e4bd82a210e7da0b973d9690adc8889.css">')
document.write('<div id=\"gist13246773\" class=\"gist\">\n    <div class=\"gist-file\">\n      <div class=\"gist-data\">\n        <div class=\"js-gist-file-update-container js-task-list-container file-box\">\n  <div id=\"file-range-updates-and-point-queries-py\" class=\"file\">\n    \n\n  <div itemprop=\"text\" class=\"blob-wrapper data type-python\">\n      <table class=\"highlight tab-size js-file-line-container\" data-tab-size=\"8\">\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L1\" class=\"blob-num js-line-number\" data-line-number=\"1\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC1\" class=\"blob-code blob-code-inner js-file-line\"><span class=\"pl-c\"><span class=\"pl-c\">#<\/span> A[] is the original array<\/span><\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L2\" class=\"blob-num js-line-number\" data-line-number=\"2\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC2\" class=\"blob-code blob-code-inner js-file-line\"><span class=\"pl-c\"><span class=\"pl-c\">#<\/span> ft[] is the fenwick tree maintaining the diffs initialized with 0<\/span><\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L3\" class=\"blob-num js-line-number\" data-line-number=\"3\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC3\" class=\"blob-code blob-code-inner js-file-line\"> <\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L4\" class=\"blob-num js-line-number\" data-line-number=\"4\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC4\" class=\"blob-code blob-code-inner js-file-line\"><span class=\"pl-c\"><span class=\"pl-c\">#<\/span> Add v to A[p]<\/span><\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L5\" class=\"blob-num js-line-number\" data-line-number=\"5\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC5\" class=\"blob-code blob-code-inner js-file-line\">update(p, v):<\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L6\" class=\"blob-num js-line-number\" data-line-number=\"6\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC6\" class=\"blob-code blob-code-inner js-file-line\">  <span class=\"pl-k\">for<\/span> (; p <span class=\"pl-k\">&lt;=<\/span> N; p <span class=\"pl-k\">+<\/span>= p<span class=\"pl-k\">&amp;<\/span>(<span class=\"pl-k\">-<\/span>p))<\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L7\" class=\"blob-num js-line-number\" data-line-number=\"7\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC7\" class=\"blob-code blob-code-inner js-file-line\">    ft[p] <span class=\"pl-k\">+=<\/span> v 	 <\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L8\" class=\"blob-num js-line-number\" data-line-number=\"8\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC8\" class=\"blob-code blob-code-inner js-file-line\">\n<\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L9\" class=\"blob-num js-line-number\" data-line-number=\"9\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC9\" class=\"blob-code blob-code-inner js-file-line\"><span class=\"pl-c\"><span class=\"pl-c\">#<\/span> Add v to A[a...b] <\/span><\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L10\" class=\"blob-num js-line-number\" data-line-number=\"10\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC10\" class=\"blob-code blob-code-inner js-file-line\">update(a, b, v):     <\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L11\" class=\"blob-num js-line-number\" data-line-number=\"11\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC11\" class=\"blob-code blob-code-inner js-file-line\">  update(a, v)     <\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L12\" class=\"blob-num js-line-number\" data-line-number=\"12\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC12\" class=\"blob-code blob-code-inner js-file-line\">  update(b <span class=\"pl-k\">+<\/span> <span class=\"pl-c1\">1<\/span>, <span class=\"pl-k\">-<\/span>v)  	 <\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L13\" class=\"blob-num js-line-number\" data-line-number=\"13\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC13\" class=\"blob-code blob-code-inner js-file-line\">\n<\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L14\" class=\"blob-num js-line-number\" data-line-number=\"14\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC14\" class=\"blob-code blob-code-inner js-file-line\"><span class=\"pl-c\"><span class=\"pl-c\">#<\/span> Return A[b]	 <\/span><\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L15\" class=\"blob-num js-line-number\" data-line-number=\"15\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC15\" class=\"blob-code blob-code-inner js-file-line\">query(b):     <\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L16\" class=\"blob-num js-line-number\" data-line-number=\"16\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC16\" class=\"blob-code blob-code-inner js-file-line\">  <span class=\"pl-c1\">sum<\/span> <span class=\"pl-k\">=<\/span> <span class=\"pl-c1\">0<\/span>     <\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L17\" class=\"blob-num js-line-number\" data-line-number=\"17\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC17\" class=\"blob-code blob-code-inner js-file-line\">  <span class=\"pl-k\">for<\/span>(; b <span class=\"pl-k\">&gt;<\/span> <span class=\"pl-c1\">0<\/span>; b <span class=\"pl-k\">-<\/span>= b<span class=\"pl-k\">&amp;<\/span>(<span class=\"pl-k\">-<\/span>b))<\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L18\" class=\"blob-num js-line-number\" data-line-number=\"18\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC18\" class=\"blob-code blob-code-inner js-file-line\">    <span class=\"pl-c1\">sum<\/span> <span class=\"pl-k\">+=<\/span> ft[b]<\/td>\n      <\/tr>\n      <tr>\n        <td id=\"file-range-updates-and-point-queries-py-L19\" class=\"blob-num js-line-number\" data-line-number=\"19\"><\/td>\n        <td id=\"file-range-updates-and-point-queries-py-LC19\" class=\"blob-code blob-code-inner js-file-line\">  <span class=\"pl-k\">return<\/span> <span class=\"pl-c1\">sum<\/span> <span class=\"pl-k\">+<\/span> A[b]<\/td>\n      <\/tr>\n<\/table>\n\n  <\/div>\n\n  <\/div>\n  \n<\/div>\n\n      <\/div>\n      <div class=\"gist-meta\">\n        <a href=\"https://gist.github.com/kartikkukreja/241ccb8758d625f1904f/raw/4ed7943c8f84d2369339bd3f1b2582978d095b09/Range%20Updates%20and%20Point%20Queries.py\" style=\"float:right\">view raw<\/a>\n        <a href=\"https://gist.github.com/kartikkukreja/241ccb8758d625f1904f#file-range-updates-and-point-queries-py\">Range Updates and Point Queries.py<\/a>\n        hosted with &#10084; by <a href=\"https://github.com\">GitHub<\/a>\n      <\/div>\n    <\/div>\n<\/div>\n')
