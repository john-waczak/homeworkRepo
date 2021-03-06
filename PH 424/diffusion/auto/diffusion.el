(TeX-add-style-hook
 "diffusion"
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
    "pdfpages")
   (TeX-add-symbols
    '("expectation" 1)
    '("matrixel" 3)
    '("bracket" 2)
    '("ket" 1)
    '("bra" 1)
    "R"
    "C"
    "F")
   (LaTeX-add-labels
    "fig:initial_configuration"
    "fig:time_evolution")
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

