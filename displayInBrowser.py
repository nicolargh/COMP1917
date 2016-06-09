#!/usr/bin/python

# A python script for displaying images created in your browswer.
# It is designed for people who are working over ssh and can't see images
# created. 
# It works by copying images from a private directory to your public_html
# directory.
# It's not the best, as it's designed to work for the chessboard activity.

from optparse import OptionParser
import os
from shutil import copy
import subprocess

parser = OptionParser()
parser.add_option("-f", "--file", type="string", dest="filename",
                         help="The file you'd display")

options, _ = parser.parse_args()

DESTINATION = os.path.join(os.path.expanduser("~"), "public_html/comp1917")
if not os.path.exists(DESTINATION):
    os.makedirs(DESTINATION)
    os.chmod(DESTINATION, 0755)

ZID = (subprocess.check_output("whoami", shell=True)).rstrip()

if not options.filename:
    print "Please give a file to print with the -f flag."
elif not os.path.isfile(options.filename):
    print "File not found. Please check " + options.filename + " and try again."
else:
    copy(options.filename, os.path.join(DESTINATION, options.filename))
    text = ("<IMG SRC=\"" + options.filename + "\" ALT=\"image??\" WIDTH=512 HEIGHT=512>")
    webpage = os.path.join(DESTINATION, os.path.basename(options.filename)) + ".html"
    f = open(webpage, "w+")
    f.write(text)
    f.close()
    print "See image at www.cse.unsw.edu.au/~" + ZID + "/comp1917/"  + os.path.basename(webpage)
    os.chmod(os.path.join(DESTINATION, options.filename), 0755)
    os.chmod(os.path.join(DESTINATION, options.filename) + ".html", 0755)
