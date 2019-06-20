(TeX-add-style-hook
 "presentation"
 (lambda ()
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "amsmath")
   (TeX-add-symbols
    '("outter" 2)
    '("expectation" 1)
    '("matrixel" 3)
    '("bracket" 2)
    '("ket" 1)
    '("bra" 1)))
 :latex)

