(TeX-add-style-hook
 "hw2"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "a4paper" "11pt")))
   (add-to-list 'LaTeX-verbatim-environments-local "lstlisting")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "lstinline")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "geometry"
    "graphicx"
    "amsmath"
    "amssymb"
    "amsthm"
    "ulem"
    "enumitem"
    "pdfpages"
    "empheq"
    "listings")
   (TeX-add-symbols
    '("threevec" 2)
    '("bvec" 1)
    '("unit" 1)
    '("basis" 1)
    '("expectation" 1)
    '("matrixel" 3)
    '("bracket" 2)
    '("ket" 1)
    '("bra" 1)
    '("prob" 2)
    "R"
    "C"
    "F"
    "E"
    "M"
    "sphere")
   (LaTeX-add-environments
    "solution")
   (LaTeX-add-amsthm-newtheorems
    "theorem"
    "corollary"
    "lemma"
    "definition"
    "Example"
    "Remark"))
 :latex)

