from SCons.Script import *

class VariantHelper:
    def __init__(self, variant_dir):
        self.variant_dir = variant_dir
        
    
    def build_variant(self, variant_file):
        SConscript(variant_file, variant_dir=self.variant_dir, duplicate=0)
    
    def build_all(self):
        variants = self.get_v_list()
        for variant in variants:
            self.build_variant(variant)
    
    def get_v_list(self):
        print "Loading variants..."
        with open('variant_list.txt') as f:
            variant_text = f.read()
        variants = []
        for line in variant_text.splitlines():
            
            if line == "":
                continue
            
            variants.append(line)
        
        return variants