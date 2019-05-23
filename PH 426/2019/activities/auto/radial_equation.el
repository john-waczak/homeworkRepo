(TeX-add-style-hook
 "radial_equation"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "a4paper" "11pt")))
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
    "listings"
    "hyperref")
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
    "R"
    "C"
    "F"
    "E"
    "M"
    "sphere")
   (LaTeX-add-environments
    "solution"))
 :latex)

