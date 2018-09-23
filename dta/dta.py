#!/usr/bin/env python3

from html.parser import HTMLParser
import psutil
import re, sys
import urllib.request

class ParseLinks(HTMLParser):
    file_types = {}
    def init(self, url):
        # here goes the curl
        # handle unicode stuff
        self.html_text = ""
        self.isFile = re.compile(r'[a-zA-Z0-9_.@\-()]+\.[a-z0-9]*')
        self.downloader = urllib.request.urlretrieve
        with urllib.request.urlopen(url) as html:
            self.html_text = html.read().decode("utf-8")
        print(self.html_text[:30])


    def getLinks(self):
        self.feed(self.html_text)

    def dir_statistics(self):
        if len(self.file_types) < 1:
            print("get links first", file=sys.stderr)
            # TODO: Exit gracefully, not this way
            sys.exit(1)
        else:
            for ext in self.file_types.keys():
                print("Ext: {} With {} files".format(ext, len(self.file_types[ext])))

    def select_down(self):
        print("Select which files download first ")
        for idx, ext in enumerate(self.file_types.keys()):
            print("{} :: {} ".format(idx, ext))

    def _classify_link(self, link):
        # get extension, file name, download url
        #get_ext_and_url = lambda url,:   
        url_seg = link.split('/')
        if self.isFile.match(url_seg[-1]):
            _, ext = url_seg[-1].split('.')
            try:
                self.file_types[ext].append((url_seg[-1], link))
            except:
                self.file_types[ext] = []
                self.file_types[ext].append((url_seg[-1], link))
            
        else:
            pass #print("not a file {}".format(url_seg[-1]))

    def handle_starttag(self, tag, attrs):
        if "a" == tag:
            for at in attrs:
                if at[0] == "href":
                    self._classify_link(at[1])


def main():
    p = ParseLinks()
    p.init("https://web.stanford.edu/~boyd/cvxbook/cvxbook_additional_exercises/")
    p.getLinks()
    p.select_down()
    p.dir_statistics()
    

if __name__ == "__main__":
    main()