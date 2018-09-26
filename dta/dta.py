#!/usr/bin/env python3

from html.parser import HTMLParser
import psutil
import re, sys
import urllib.request
from urllib.parse import unquote as url_unquote

class ParseLinks(HTMLParser):
    file_types = {}
    def init(self, url):
        # here goes the curl
        # handle unicode stuff
        self.html_text = ""
        self.base_url = url
        self.isFile = re.compile(r'[a-zA-Z0-9_.@\-()\[\]]+\.[a-z0-9]*')
        self.downloader = urllib.request.urlretrieve
        with urllib.request.urlopen(url) as html:
            
            self.html_text = html.read().decode("utf-8")
            if len(self.html_text) < 5:
                print("Error fetching the html", file=sys.stderr)
                exit(1)


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
        opts = []
        exts = []
        for idx, ext in enumerate(self.file_types.keys()):
            print("{} :: {} ".format(idx, ext))
            opts.append(idx)
            exts.append(ext)
        print("q :: To exit")
        sel = input()
        if sel == 'q':
            return -99
        elif int(sel) in opts:
            return exts[int(sel)]
        else:
            return -1

    def down_list(self):
        while len(self.file_types) > 0:
            # still files to download
            self.dir_statistics()
            down_type = self.select_down()
            if -99 == down_type:
                print("Exit DTA")
                exit()
            print("Start download of {} files".format(down_type))
            for fname, url in self.file_types[down_type]:
                # check if its a full url or the server local
                if "http" not in url:
                    url = "/".join([self.base_url,url])
                print("Request file: {}".format(url))
                self.downloader(url, fname )
            self.file_types.pop(down_type)

    def _classify_link(self, link):
        # get extension, file name, download url
        #get_ext_and_url = lambda url,:
        ## Parse the link to a file format name 
        print("full link: {}".format(link))
        print("Base url {}".format(self.base_url))
        url_seg = url_unquote(link).replace(" ", "_").split('/')
        print(url_seg) # = link.split('/')
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
        """
        Handle the tag a|A
        """
        if "a" == tag.lower():
            for at in attrs:
                if at[0].lower() == "href":
                    self._classify_link(at[1])
        else:
            pass ## not interested in other tags which are not links

def main():
    p = ParseLinks()
    #p.init("https://web.stanford.edu/~boyd/cvxbook/cvxbook_additional_exercises/")
    p.init("http://afewbitsmore.com:2525/albums/Air/Love%202%20[2009]/")
    p.getLinks()
    p.down_list()
    

if __name__ == "__main__":
    main()