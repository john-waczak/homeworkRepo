# e.g. python3 combine_PDFs.py output.pdf
import glob
import os, sys


pdf_files = []
for f in glob.glob("*.pdf"):
    fname = f[:-4]
    pdf_files.append(int(fname))

pdf_files.sort()
pdf_files = [str(pdf)+".pdf" for pdf in pdf_files]

# print out the files for the combine
os.system("pdfunite " + " ".join(pdf_files)+" ../"+sys.argv[1])
