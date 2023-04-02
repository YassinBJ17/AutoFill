#---------------------------------------------------------------------------------------------------------------
#|    Pour le moment: Permet de créer les .LUP depuis un elf avec en entrée, l'archi mémoire FADEX et .elf     |
#---------------------------------------------------------------------------------------------------------------

#Lief est utilisé pour dumper le .elf, parser et mettre le tout sous paramètre
#OS pour la manipulation de fichiers/dossiers
#Subprocress pour appeller le .bat en cours de route
#Hashlib pour comparer deux fichiers par le shall
#search pour comparer deux noms de fichiers dans la génération du FLS : ".ini/.sav à éviter"
#shutil pour remettre à jour les trois dossiers : "bat/gen_fls/conf_fls" créer lors de l'appel du script Python
#Tkinter + sys pour récuperer par GUI depuis l'utilisateur : VOIE // SW_NAME // SW_VERSION // OLL ou T32

import lief
from tkinter import *
from tkinter.ttk import Combobox
import os
import subprocess
import hashlib
from re import search
import shutil
import sys
import stat
import re
import sys
import argparse


def del_rw(action, name, exc):
    os.chmod(name, stat.S_IWRITE)
    os.remove(name)

#------------------------
#|    Init Parameter    |
#------------------------
    
#Nombre de lignes dans la table
nb_ligne = 40
nb_col = 2

count_parse_elf = 0
count_parse_bin = 0

bin_name_original = 0

#Variable utilisée pour connaitre les sections vides et les écarter de l'éxtraction .LUP
index_find = [[] for i in range(nb_ligne)]

#Variable utilisée pour connaitre l'adresse de démarrage pour le .LUP pour chaque ligne
address_sector_SUP = [4294967295 for p in range(nb_ligne)]

type_sector_SUP = ["type = app" for p in range(nb_ligne)]

#Récupére le chemin du répertoire 
# print(sys.argv[0]) -> fonctionne si on appel le script par son chemin complet
#os.path.dirname(sys.argv[0])
# Peut créer des soucis 
#print(os.getcwd())
# Peut créer des soucis, fonctionne pour le .py mais pas pour le .exe 
#print(os.path.dirname(os.path.abspath( __file__ )))

path = os.path.dirname(sys.argv[0])
print(f'Path = {path}')
if path == '' :
    path = '.'

#Remove all Read only from the folder
remove_ro_bat = "attrib -R " + path + "\* /S"
subprocess.run(remove_ro_bat, stdout=subprocess.PIPE)

#Nom du dossier associé : TO BE REPLACED BY GUI
directory_gui = path + "\\gui_maker\\"
directory_elf = path + "\\elf\\"
directory_bin = path + "\\bin\\"
directory_gen_fls = path + "\\gen_fls\\"
directory_bat = path + '\\bat\\'
directory_conf_fls = path + "\\conf_fls\\"
directory_bin_utils = path + "\\bin_utils\\"
directory_log_gen = path + "\\log\\"
directory_script_gen = path + "\\script\\"
directory_script_gen_phoenix = path + "\\script\\PHOENIX"
directory_script_gen_t32 = path + "\\script\\T32"
directory_certificates = path + "\\certificates\\DEV_ROOT_CERT\\"

cartridge = "R:\source\oss\cartridge\cartridge_init.c"

if not os.path.exists(directory_conf_fls):
    os.makedirs(directory_conf_fls)
    
if not os.path.exists(directory_bat):
    os.makedirs(directory_bat)

shutil.rmtree(directory_conf_fls, ignore_errors=True, onerror = del_rw)
shutil.rmtree(directory_bat, ignore_errors=True, onerror = del_rw)
shutil.rmtree(directory_script_gen, ignore_errors=True, onerror = del_rw)
shutil.rmtree(directory_log_gen, ignore_errors=True, onerror = del_rw)

if not os.path.exists(directory_conf_fls):
    os.makedirs(directory_conf_fls)

filename_sup = "sup_conf.ini"
filename_sif = "sif_conf.ini"
filename_luh = "luh_conf.ini"
filename_cmp = "cmp_conf.ini"
filename_lud = "lud_conf.ini"

Extracted_bat_section = path+"\\bat\\Extracted_LUP_section.bat"
genFLS_bat_section = path+"\\bat\\genFLS.bat"
output_log_id = path+"\\log\\output_id.log"
output_log_genfls = path+"\\log\\output_fls.log"
FLASH_cmm_bat = path+"\\script\\T32\\flash_FLS.bat"

type_SUP = "type = public_tbl\n"

destination = "\n"

os.makedirs(os.path.dirname(Extracted_bat_section), exist_ok=True)
os.makedirs(os.path.dirname(genFLS_bat_section), exist_ok=True)
os.makedirs(os.path.dirname(output_log_id), exist_ok=True)
os.makedirs(os.path.dirname(output_log_genfls), exist_ok=True)

with open(Extracted_bat_section, "w") as f:
    f.write("REM Extracted LUP HEADER\n")
    
with open(output_log_id, "w") as f:
    f.write("Identify of generated FLS : \n\n")
    
with open(output_log_genfls, "w") as f:
    f.write("GEN_FLS Log : \n\n")
        
#Création du fichier .bat qui va être appelé pour générer le FLS
Fill_section_bat = open(Extracted_bat_section,"a")
genFLS_bat = open(genFLS_bat_section,"a")
log_bat_id = open(output_log_id,"a+")
log_bat_fls = open(output_log_genfls,"a+")

#lud_activated only if primary : Done by the check for K2.elf which is type = main
lud_activated = 0
lud_in_sif = "\n"
lud_in_luh = "\n"

#----------------
#|    HEADER     |
#----------------

#Archi FADEX du mois de mai: Utilisé pour découper les .LUP sans contiguité
mem_archi = [ [ 16777216 , 17039359, "ASTERIOS" ],          #ASTERIOS           0x01000000 // 0x0103FFFF
    [ 17039360 , 17301503, "G4_OSS_APP" ],                  #G4 OSS App         0x01040000 // 0x0107FFFF
    [ 17301504 , 17563647, "G3_OSS_APP" ],                  #G3 OSS App         0x01080000 // 0x010BFFFF
    [ 17563648 , 17661951, "XT" ],                          #XT Parto           0x010C0000 // 0x010D7FFF
    [ 17661952 , 17793023, "EH" ],                          #EH Parto           0x010D8000 // 0x010F7FFF
    [ 17793024 , 17825791, "MCSS_RSF" ],                    #MCSS RSF           0x010F8000 // 0x010FFFFF
    [ 17825792 , 18087935, "MCSS_CONF_TABLE" ],             #MCSS_CONF_TABLE    0x01100000 // 0x0113FFFF
    [ 18087936 , 18096127, "MCSS_WRAP_DATA" ],              #MCSS_WRAP_DATA     0x01140000 // 0x01141FFF
    [ 18096128 , 18227199, "MCSS_WRAP_RODATA" ],            #MCSS_WRAP_RODATA   0x01142000 // 0x01161FFF
    [ 18227200 , 18350079, "SPARE1" ],                      #SPARE1             0x01162000 // 0x0117FFFF
    [ 18350080 , 18612223, "MCSS_WRAP_TXT" ],               #MCSS_WRAP_TXT      0x01180000 // 0x011BFFFF
    [ 18612224 , 18616319, "MCSS_RSF_TXT" ],                #MCSS_RSF_TXT       0x011C0000 // 0x011C0FFF
    [ 18616320 , 18616327, "MCSS_TSK_POINT" ],              #MCSS_TSK_POINT     0x011C1000 // 0x011C1007
    [ 18616328 , 18681863, "CRIT_SERV_RODATA" ],            #CRIT_SERV_RODATA   0x011C1008 // 0x011D1007
    [ 18681864 , 18681883, "CSS_GX_POINT_TAB" ],            #CSS_GX_POINT_TAB   0x011D1008 // 0x011D101B
    [ 18681884 , 18682139, "CSS_MCSS_POINTTAB" ],           #CSS_MCSS_POINTTAB  0x011D101C // 0x011D111B
    [ 18682140 , 18683675, "G3_OSS_COPYTAB_ID" ],           #G3_OSS_COPYTAB_ID  0x011D111C // 0x011D171B
    [ 18683676 , 18685211, "G4_OSS_COPYTAB_ID" ],           #G4_OSS_COPYTAB_ID  0x011D171C // 0x011D1D1B
    [ 18685212 , 18686235, "UOD_OSS_COPYTAB_ID" ],          #UOD_OSS_COPYTAB_ID 0x011D1D1C // 0x011D211B
    [ 18686236 , 18776063, "SPARE2" ],                      #SPARE2             0x011D211C // 0x011E7FFF
    [ 18776064 , 18808831, "IBIT_RSF_RODATA" ],             #IBIT_RSF_RODATA    0x011E8000 // 0x011EFFFF
    [ 18808832 , 18874367, "OSS_RODATA" ],                  #OSS_RODATA         0x011F0000 // 0x011FFFFF
    [ 18874368 , 19136511, "OSS_CONF_TABLE" ],              #OSS_CONF_TABLE     0x01200000 // 0x0123FFFF
    [ 19136512 , 19202047, "IBIT_RSF_TXT" ],                #IBIT_RSF_TXT       0x01240000 // 0x0124FFFF
    [ 19202048 , 19333119, "OSS_TXT" ],                     #OSS_TXT            0x01250000 // 0x0126FFFF
    [ 19333120 , 19398655, "CRIT_SERV_TXT" ],               #CRIT_SERV_TXT      0x01270000 // 0x0127FFFF
    [ 19398656 , 19922943, "CSS_CONF_GX_TAB" ],             #CSS_CONF_GX_TAB    0x01280000 // 0x012FFFFF
    [ 19922944 , 20971519, "CSS_WRAP_GX_RODATA" ],          #CSS_WRAP_GX_RODATA 0x01300000 // 0x013FFFFF
    [ 20971520 , 22020095, "CSS_WRAP_GX_DATA" ],            #CSS_WRAP_GX_DATA   0x01400000 // 0x014FFFFF
    [ 22020096 , 22036479, "CSS_RSF_GX_RODATA" ],           #CSS_RSF_GX_RODATA  0x01500000 // 0x01503FFF
    [ 22036480 , 22052863, "CSS_RSF_G4_RODATA" ],           #CSS_RSF_G4_RODATA  0x01504000 // 0x01507FFF
    [ 22052864 , 22118399, "CSS_RSF_G23_RODATA" ],          #CSS_RSF_G23_RODATA 0x01508000 // 0x01517FFF
    [ 22118400 , 22263807, "SPARE3" ],                      #SPARE3             0x01518000 // 0x0153B7FF
    [ 22263808 , 22267903, "CSS_RSF_GX_TXT" ],              #CSS_RSF_GX_TXT     0x0153B800 // 0x0153C7FF
    [ 22267904 , 22271999, "CSS_RSF_G4_TXT" ],              #CSS_RSF_G4_TXT     0x0153C800 // 0x0153D7FF
    [ 22272000 , 22282239, "CSS_RSF_G3_TXT" ],              #CSS_RSF_G3_TXT     0x0153D800 // 0x0153FFFF
    [ 22282240 , 23330815, "CSS_WRAP_GX_TXT" ],             #CSS_WRAP_GX_TXT    0x01540000 // 0x0163FFFF
    [ 23330816 , 23461887, "CSS_RSF_UOD_TXDAT" ],           #CSS_RSF_UOD_TXDAT  0x01640000 // 0x0165FFFF
    [ 23461888 , 23592959, "STUB_UOD_OSS_APP" ],            #STUB_UOD_OSS_APP   0x01660000 // 0x0167FFFF
    [ 23592960 , 23855103, "MCSS_WRAP_AG_TSK" ],            #MCSS_WRAP_AG_TSK   0x01680000 // 0x016BFFFF
    ]
    
pn_format = re.compile("^([A-Z0-9]{3})([0-9A-F]{2})([0-9A-HJ-NPR-Y-]{10})$")

def computeCc(pn):
    cvr = ('0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F')

    match = pn_format.match(pn)
    pn_part = match[1] + match[3].replace('-','')
    pn_ascii=list(map(ord, pn_part))
    cc=pn_ascii[0]
    for char_i in pn_ascii[1:]:
        cc=cc^char_i
    return format((cc >> 4) & 0xF, 'X') + format(cc & 0xF, 'X')

def isPnValid(pn):
    match = pn_format.match(pn)
    if match and (match[2] == computeCc(pn)):
        return True
    else:
        return False
    
#------------------------
#|    Create the GUI    |
#------------------------

def GUI() :
    settingsWindow = Tk()
    settingsWindow.title("FeLiX FLS Generator for FADEX")

    dict_sw_names = { '':'',"OSS_CU" : "T0179" , "OSS_CONF":"T0181", "CSS_MCSS" : "T0178", "MRAM_APP" : "T0177"}
    SFI_status = "SFI NOK"
    SFI_foreground = 'red'

    def action(e) :
        SFI = entrySFI.get().upper()
        sw_name = entrySW_NAME.get()
        sw_version = entrySW_VERSION.get().upper()
        if sw_version != '' :
            sw_version = 'T' + sw_version.replace('.','').zfill(4)
        entrySFI.delete(0, len(SFI))
        entrySFI.insert(0,dict_sw_names[sw_name] + sw_version)


    def check_SFI() :
        SFI = entrySFI.get()
        bodyCRC = ''
        footerCRC = ''
        if len(SFI) == 15 :
            bodyCRC = SFI[5:10]
            footerCRC = SFI[10:15]
            SFI_status = "SFI OK"
            SFI_foreground = 'light green'
        elif len(SFI) == 10 :
            bodyCRC = SFI[0:5]
            footerCRC = SFI[5:10]
            SFI_status = "SFI OK"
            SFI_foreground = 'light green'
        else :
            SFI_status = "SFI NOK"
            SFI_foreground = 'red'
        computedCRC = "SFI00" + bodyCRC + footerCRC
        try :        
            headerCRC = computeCc(computedCRC)
            LOAD_PN = "SFI" + headerCRC + bodyCRC + footerCRC
        except TypeError :
            pass       
        SFI_status_display.config(text = SFI_status, fg = SFI_foreground)
        if SFI_status == "SFI OK" :
            entrySFI.delete(0, len(SFI))
            entrySFI.insert(0,LOAD_PN)
            return
    
    def generate() :
        global SW_NAME
        global SW_VERSION 
        global SFI_NAME
        global VOIE
        global TELECHARGEMENT
        global ELFBIN
        global ADDRBIN
        
        SW_NAME = entrySW_NAME.get().upper()
        SW_VERSION = entrySW_VERSION.get().upper()
        SFI_NAME = entrySFI.get().upper()
        VOIE = entryVOIE.get().upper()
        TELECHARGEMENT = entryTELECHARGEMENT.get().upper()
        ELFBIN = entryELFBIN.get().upper()
        ADDRBIN = entryADDRBIN.get().upper()

        settingsWindow.destroy()


    #settingsWindow = Tk()

    SW_VERSION_def = StringVar()
    SFI_def = StringVar()
    VOIE_def = StringVar()
    TELECHARGEMENT_def = StringVar()
    ELFBIN_def = StringVar()
    ADDRBIN_def = StringVar()

    #Centralise la bordule centrale
    left_frame = Frame(settingsWindow, bg='#4065A4', width=360, height=480)
    right_frame = Frame(settingsWindow, bg='#4065A4', width=600, height=480)
    left_frame.pack(side='left', fill='both', padx=10, pady=5, expand=True)
    right_frame.pack(side='right', fill='both', padx=10, pady=5, expand=True)

    # Create left_frame
    image  =  PhotoImage(file=directory_gui + "\FLX.png")
    original_image  =  image.zoom(2,2)
    Label(left_frame,  image=original_image, borderwidth=0, highlightthickness = 0).pack(fill='both',  padx=5,  pady=5)

    Label(left_frame,  text="Creation de FLS pour FADEX", font =("Helvetica", 30), bg = '#4065A4', fg = 'white').pack(side='bottom',  padx=5,  pady=5)

    #Create right_frame (Top//Bottom)
    para_fls_frame = Frame(right_frame,  width=90,  height=185, bg = '#4065A4', highlightbackground = "white", highlightcolor= "white", highlightthickness=5)
    para_fls_frame.pack(side='top',  fill='both',  padx=5,  pady=5,  expand=True)

    button_gen_frame = Frame(right_frame,  width=90,  height=185, bg = '#4065A4', highlightbackground = "white", highlightcolor= "white", highlightthickness=5)
    button_gen_frame.pack(side='bottom',  fill='both',  padx=5,  pady=5,  expand=True)

    Label(para_fls_frame,  text="SW_NAME", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 0, column = 0, padx=5,  pady=5, sticky=W)
    Label(para_fls_frame,  text="SW_VERSION", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 1, column = 0, padx=5,  pady=5, sticky=W)
    Label(para_fls_frame,  text="SFI (Enter ZSSSSZXXXX)", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 2, column = 0, padx=5,  pady=5, sticky=W)
    Label(para_fls_frame,  text="Format : SFIccZSSSSZXXXX", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 3, column = 0, padx=5,  pady=5, sticky=W)
    SFI_status_display = Label(para_fls_frame,  text=SFI_status, justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = SFI_foreground)
    SFI_status_display.grid(row = 3, column = 1, padx=5,  pady=5, sticky = E)
    Label(para_fls_frame,  text="VOIE (A/B/AB)", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 4, column = 0, padx=5,  pady=5, sticky=W)
    Label(para_fls_frame,  text="TELECHARGEMENT (OLL/T32)", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 5, column = 0, padx=5,  pady=5, sticky=W)
    Label(para_fls_frame,  text="PARSE (ELF/BIN)", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 6, column = 0, padx=5,  pady=5, sticky=W)
    Label(para_fls_frame,  text="Adresse (for BIN only)", justify = CENTER, font =("Helvetica", 15), bg = '#4065A4', fg = 'white').grid(row = 7, column = 0, padx=5,  pady=5, sticky=W)

    entrySW_NAME = Combobox(para_fls_frame,justify = CENTER, font =("Helvetica", 15), values= list(dict_sw_names.keys()))
    #SW_NAME_def
    entrySW_NAME.grid(row = 0, column = 1, padx=5,  pady=5)

    entrySW_VERSION = Entry(para_fls_frame,  bd = 5, justify = CENTER, font =("Helvetica", 15), bg = 'white', textvariable=SW_VERSION_def)
    entrySW_VERSION.grid(row = 1, column = 1, padx=5,  pady=5)

    entrySFI = Entry(para_fls_frame,  bd = 5, justify = CENTER, font =("Helvetica", 15), bg = 'white', textvariable=SFI_def)
    entrySFI.grid(row = 2, column = 1, padx=5,  pady=5)
    

    entryVOIE = Entry(para_fls_frame,  bd = 5, justify = CENTER, font =("Helvetica", 15), bg = 'white', textvariable=VOIE_def)
    entryVOIE.grid(row = 4, column = 1, padx=5,  pady=5)

    entryTELECHARGEMENT = Entry(para_fls_frame,  bd = 5, justify = CENTER, font =("Helvetica", 15), bg = 'white', textvariable=TELECHARGEMENT_def)
    entryTELECHARGEMENT.grid(row = 5, column = 1, padx=5,  pady=5)

    entryELFBIN = Entry(para_fls_frame,  bd = 5, justify = CENTER, font =("Helvetica", 15), bg = 'white', textvariable=ELFBIN_def)
    entryELFBIN.grid(row = 6, column = 1, padx=5,  pady=5)

    entryADDRBIN = Entry(para_fls_frame,  bd = 5, justify = CENTER, font =("Helvetica", 15), bg = 'white', textvariable=ADDRBIN_def)
    entryADDRBIN.grid(row = 7, column = 1, padx=5,  pady=5)


    # Création du Bouton create FLS

    entrySW_NAME.bind("<<ComboboxSelected>>", action)
    entrySW_VERSION.bind("<Return>", action)
    
    Button(para_fls_frame,  text="Check SFI", justify = CENTER, font =("Helvetica", 15), bg = 'white',  command=check_SFI).grid(row = 3, column = 1, padx=5,  pady=5, sticky=W)    
    Button(button_gen_frame,  text="Generate FLS", font =("Helvetica", 15), bg = 'white', command=generate).place(relx=0.5, rely=0.5, anchor=CENTER)

    #Afficher la fenêtre
    settingsWindow.mainloop()

#------------------------
#|    End ofthe GUI     |
#------------------------

#--------------------
#|    CONFIG_FLS     |
#--------------------

if __name__ == "__main__":

    parser = argparse.ArgumentParser(prog=os.path.basename(__file__),
                                description='FLS Build chain',
                                fromfile_prefix_chars='@',
                                formatter_class=argparse.RawTextHelpFormatter)

    parser.add_argument('-v', '--version', action='version', version="0.3")
    parser.add_argument('-cmd', '--command',  action='store_true', help='Choose between execute program with command lines or GUI')

    parser.add_argument('-sfi', '--loadableSoftwarePN', type=str, default='SFIccT0179T0000', help='Selected SFI')
    parser.add_argument('-elf', '--elffile', action='store_true', help='Input files are .elf')
    parser.add_argument('-bin', '--binfile', type=str, default='0x01200000', help='Input files are raw binary')
    parser.add_argument('-dl', '--download', type=str, default='oll', help='choose download type oll or T32')
    parser.add_argument('-i', '--input', type=str, default='', help='choose input txt file for path to bin file')
    parser.add_argument('-o', '--out', type=str, default=directory_gen_fls, help='choose output folder')
    parser.add_argument('-n', '--name', type=str, default='', help='Name')

    try :
        args = parser.parse_args()
    except AttributeError as err:
        with open(output_log_id, "a") as f:
            print(err)
            f.write(err)
            parser.print_help()
            f.write(parser.print_help())
        sys.exit()

    directory_gen_fls = args.out
    # TO DO
    if not os.path.exists(directory_gen_fls):
        os.makedirs(directory_gen_fls)
    shutil.rmtree(directory_gen_fls, ignore_errors=True, onerror = del_rw)
    if not os.path.exists(directory_gen_fls):
        os.makedirs(directory_gen_fls)
    with open(genFLS_bat_section, "w") as f:
        f.write("REM FLS generator command Line\nCD /D " + directory_gen_fls + "\n")        

    #redefinition of directory_elf for integration into FADEX build chain
    if args.command :
        with open(args.input) as file :
            directory_auto_elf = file.read().split('\n')

    def write(self, text):
        self.stdout.write(text)
        self.logfile.write(text)

# Initialize Global FLS Parameters
    SW_NAME = ''
    SW_VERSION = ''
    SFI_NAME = ''
    VOIE = ''
    TELECHARGEMENT = ''
    ELFBIN = ''
    ADDRBIN = ''

# Fet the parameters from cmd lines
    if args.command :
        #both channels by default
        VOIE = 'AB'
        SW_NAME = args.name.upper()
        TELECHARGEMENT = args.download.upper()
        SFI_NAME = args.loadableSoftwarePN.upper().strip()
        with open(cartridge, "r") as f :
            oss_cu_version = re.search(r'(?<=_)([0-9]{2})\.([0-9]{2})\.([0-9]{2})',f.read()).group()
            oss_cu_version = ''.join(oss_cu_version.split('.')[-2::])
        try :        
            bodyCRC = SFI_NAME[5:10]
            if SW_NAME == 'OSS_CU' :
                footerCRC = SFI_NAME[10] + oss_cu_version
            else :
                footerCRC = SFI_NAME[10:15]
            computedCRC = "SFI00" + bodyCRC + footerCRC
            headerCRC = computeCc(computedCRC)
            SFI_NAME = "SFI" + headerCRC + bodyCRC + footerCRC
        except TypeError :
            # TO DO LOG
            print(f'Wrong format for SFI')
            print(f'Format expected : SFIccXSSSSXSSSS')
            print(f'Entered format : {SFI_NAME}')
        if args.elffile :
            ELFBIN = 'ELF'
        else :
            ELFBIN = 'BIN'
            ADDRBIN = args.binfile


#Launch GUI and Get FLS Parameter from FLX
    else :
    # We want to launch GUI so no -cmd
        GUI()

    LOAD_PN = SFI_NAME
    LOAD_PN_LUH = "load_pn = " + LOAD_PN + "\n"

    
        
    with open(output_log_id, "a") as f:
        f.write("Version du FLS: " + str(SW_VERSION) + "\n")
    print("\nVersion du FLS: " + str(SW_VERSION))
    
    if isPnValid(SFI_NAME) :
        with open(output_log_id, "a") as f:
            f.write("SFI du FLS: " + str(SFI_NAME) + "\n")
        print ("SFI du FLS: " + str(SFI_NAME))
    else :
        with open(output_log_id, "a") as f:
            f.write("/!\ ERROR : Mauvais SFI, Assurez vous d'avoir clické sur \"Check SFI\": " + SFI_NAME + "\n")
            f.close()
        print ("/!\ ERROR : Mauvais SFI, Utilisez le bouton \"Check SFI\": " + SFI_NAME)
        sys.exit()
        
#Modify Load_PN according to the SW_NAME + SW_VERSION: SwPN is called   

    if ((SW_NAME == "OSS_CU") or (SW_NAME == "OSS_CONF") or (SW_NAME == "CSS_MCSS") or (SW_NAME == "MRAM_APP") or (SW_NAME == "")):
        with open(output_log_id, "a") as f:
           f.write("Nom du FLS: " + SW_NAME + "\n")
           f.close()
        print ("Nom du FLS: " + SW_NAME)
        FLS_NAME = SW_NAME
    else :
        with open(output_log_id, "a") as f:
            f.write("/!\ ERROR : Mauvaise configuration du nom du FLS, nom choisi: " + SW_NAME + "\n")
            f.close()
        print ("/!\ ERROR : Mauvaise configuration du nom du FLS, nom choisi: " + SW_NAME)
        sys.exit()

    if ((VOIE == 'A') or (VOIE == 'B') or (VOIE == 'AB')) :    
        with open(output_log_id, "a") as f:
            f.write("Voie du FLS: " + VOIE + "\n")
            f.close()
        print ("Voie du FLS: " + VOIE)
        VOIE_FLS = VOIE
    else :
        with open(output_log_id, "a") as f:
            f.write("/!\ ERROR : Mauvaise configuration de la voie, voie choisie: " + VOIE + "\n")
            f.close()
        print ("/!\ ERROR : Mauvaise configuration de la voie, voie choisie: " + VOIE)
        sys.exit()

    if ((TELECHARGEMENT == "OLL") or (TELECHARGEMENT == "T32")) :
        with open(output_log_id, "a") as f:
            f.write("telechargement choisi: " + TELECHARGEMENT + "\n")
            f.close()
        print ("telechargement choisi: " + TELECHARGEMENT)
        FLS_LOADER = TELECHARGEMENT
    else :
        with open(output_log_id, "a") as f:
            f.write("/!\ ERROR : Mauvaise configuration du telechargement, telechargement choisi: " + TELECHARGEMENT + "\n")
            f.close()
        print ("/!\ ERROR : Mauvaise configuration du telechargement, telechargement choisi: " + TELECHARGEMENT)
        sys.exit()
        
    if ((ELFBIN == "ELF") or (ELFBIN == "BIN")) :
        with open(output_log_id, "a") as f:
            f.write("fichier de format choisi: " + ELFBIN + "\n")
            f.close()
        print ("fichier de format choisi: " + ELFBIN)
        ELFBIN_PARSE = ELFBIN
    else :
        with open(output_log_id, "a") as f:
            f.write("/!\ ERROR : Mauvaise configuration du fichier de format, format choisi: " + ELFBIN + "\n")
            f.close()
        print ("/!\ ERROR : Mauvaise configuration du fichier de format, format choisi: " + ELFBIN)
        sys.exit()
        
    if (ADDRBIN != ""):
        if (ELFBIN == "ELF"):
            with open(output_log_id, "a") as f:
                f.write("/!\ ERROR : Adresse BIN utilisé pour une génération de ELF" + "\n")
                f.close()
            print ("/!\ ERROR : Adresse BIN utilisé pour une génération de ELF")
            sys.exit()
    else :
        if (ELFBIN == "BIN"):
            with open(output_log_id, "a") as f:
                f.write("/!\ ERROR : Adresse BIN vide pour une génération de BIN \n")
                f.close()
            print ("/!\ ERROR : Adresse BIN vide pour une génération de BIN")
            sys.exit()

    if (ADDRBIN != ""):
        if (ELFBIN == "BIN"):
            adresse_SUP_temp1 = ADDRBIN
            adresse_SUP_temp2 = int(adresse_SUP_temp1, base=16)
            adresse_SUP_in_BIN = hex(adresse_SUP_temp2)
            
            with open(output_log_id, "a") as f:
                f.write("Adresse BIN à flasher en : " + adresse_SUP_in_BIN)
                f.close()
            print("Adresse BIN à flasher en : " + adresse_SUP_in_BIN)
            
            if int(adresse_SUP_in_BIN,16) >= 0x20000000 and int(adresse_SUP_in_BIN,16) < 0x21000000:
                destination = "destination = 0x42424242\n"
            elif int(adresse_SUP_in_BIN,16) >= 0x21000000 and int(adresse_SUP_in_BIN,16) < 0x22000000:
                destination = "destination = 0x32323232\n"

#Modify .LUH file depending on the Channel
    if VOIE_FLS == "A" :
        LOAD_ID = "load_type_ID = 0x1001\n"
    elif VOIE_FLS == "B" :
        LOAD_ID = "load_type_ID = 0x2001\n"
    elif VOIE_FLS == "AB" :
        LOAD_ID = "load_type_ID = 0x3001\n"

#Modify .LUH / .SIF file depending on the FLASH_TYPE
    if FLS_LOADER == "OLL" :
        SIF_FIRST_SIF = "[${load_pn}.LUH]\n\n"
        SIF_FIRST_LUH = "[APP.SIF]\npn = ${load_pn}\nname = ${load_pn}_1.SIF\ncrc = 0"
    elif FLS_LOADER == "T32" :
        SIF_FIRST_SIF = "\n"
        SIF_FIRST_LUH = "\n"

#Modify .SIF / .CMP file depending on the SW_NAME : For CDM .cmp : OSS_CU1 for VOIEA // OSS_CU2 for VOIEB / OSS_CU for VOIEAB
    if FLS_NAME == "OSS_CU":
        if VOIE_FLS == "A" :
            SW_NAME_SIF = "SW_name = OSS_CU1\n\n"
            SW_NAME_CMP = "identifier = OSS_CU1\n\n"
        if VOIE_FLS == "B" :
            SW_NAME_SIF = "SW_name = OSS_CU2\n\n"
            SW_NAME_CMP = "identifier = OSS_CU2\n\n"
        if VOIE_FLS == "AB" :
            SW_NAME_SIF = "SW_name = OSS_CU\n\n"
            SW_NAME_CMP = "identifier = OSS_CU\n\n"
    else :
        SW_NAME_SIF = "SW_name = " + FLS_NAME +"\n\n"
        SW_NAME_CMP = "identifier = "+ FLS_NAME +"\n\n"
            
    LOAD_DESCRIPTION = "load_type_description = @@Load for " + FLS_NAME + "@@\n"

#Configuration only for FADEX
#Target
    SIF_TARGET = "HW_name = SFI_EECFADEX"
    LUH_TARGET = "targets = SFI_EECFADEX\n"
#.CMP File
    BOOT_CMP = "[BOOT_CU]\nmajor = 1\nminor = 0\n\n"
    MRAM_CMP = "[MRAM_APP]\nmajor = 1\nminor = 0\n\n"
    CSS_MCSS_CMP = "[CSS_MCSS]\nmajor = 1\nminor = 0\n\n"
    HMOS_CMP = "[HMOS]\nmajor = 1\nminor = 0\n\n"
    OSS_CONF_CMP = "[OSS_CONF]\nmajor = 1\nminor = 0\n\n"
    OSS_CU_CMP = "[OSS_CU]\nmajor = 1\nminor = 0\n\n"
#.LUD File
    MRAM_LUD = "[MRAM_APP]\naddress = 0x0173A000\nlength = 0x1FFFF\nsif = 0x0172A000\n\n"
    CSS_MCSS_LUD = "[CSS_MCSS]\naddress = 0x01765000\nlength = 0x1FFFF\nsif = 0x01760000\n\n"
    OSS_CONF_LUD = "[OSS_CONF]\naddress = 0x01735000\nlength = 0x1FFFF\nsif = 0x01730000\n\n"

#Configure addresse of BIN/SIFHC from the SW_NAME

    if FLS_NAME == "OSS_CU" :
        adresse_SIFHC = 0x01770000
        adresse_BIN = 0x01775000

    elif FLS_NAME == "OSS_CONF" :
        adresse_SIFHC = 0x01730000
        adresse_BIN = 0x01735000
    
    elif FLS_NAME == "CSS_MCSS" :
        adresse_SIFHC = 0x01760000
        adresse_BIN = 0x01765000
        
    elif FLS_NAME == "MRAM_APP" :
        adresse_SIFHC = 0x0172A000
        adresse_BIN = 0x0173A000
    
    
    #--------------
    #|    BODY     |
    #--------------
    if(ELFBIN_PARSE == "ELF"):
    
        #List all file in the directory_elf
        if args.command :
            list_elf = directory_auto_elf
        else :
            list_elf = [os.path.join(directory_elf, filename) for filename in  os.listdir(directory_elf)]
        print("\n Liste des fichie sources :")
        for f in list_elf:
            print(f)
            # checking if it is a file
            if os.path.isfile(f):
                filename = os.path.basename(f)

                binary = lief.parse(f)
                
                if "k2" in filename:
                    type_SUP = "type = oper\n"
                
                #Variable utilisée pour remplir le fichier texte selon le nombre de sections utilisées
                string_find = [[] for i in range(nb_ligne)]

                #En-tête du mot cléf objcopyppc
                for i in range(nb_ligne):
                    string_find[i].append(directory_bin_utils + "objcopyppc.exe -I elf32-big -O binary")
                    
                    #SREC : FOR DEBUG ONLY
                    #string_find[i].append("objcopy -I elf32-big -O srec --srec-len 32")
                
                #Patch for K2 : use section virutal address
                if filename == "k2.elf":
                    string_find[0].append(" -j .k2_data")
                
                #Création du fichier de sortie désigner dans le BAT : Just the path
                file_generated = path + "\\gen_fls\\" + filename

                for i in range(nb_ligne):
                    index_find[i] = 0

                #Récupère les sections du fichier binaire parsé et les comparent au mapping mémoire: Doit être compris en FLASH : Minimum//Maximum
                for section in binary.sections:
                    
                    index = 0
                    
                    if section.virtual_address > mem_archi[0][0] and section.virtual_address < mem_archi[nb_ligne - 1][nb_col - 1]:
                        for i in range(0, nb_ligne):
                            if section.virtual_address > mem_archi[i][1] :
                                index = index + 1
                        string_find[index].append(" -j " + section.name)
                        index_find[index]=1
                                        
                        if address_sector_SUP[index] > section.virtual_address :
                            address_sector_SUP[index] = section.virtual_address
                            
                if "k2.elf" in filename:
                        type_sector_SUP[index] = "type = main"
                        lud_in_sif = "[APP.LUD]\nname = ${load_pn}.LUD\n\n"
                        lud_in_luh = "[APP.LUD]\npn = ${load_pn}\nname = ${load_pn}.LUD\ncheck = CRC32\n\n"
                        lud_activated = 1
                        
                        #Nom du fichier traité:
                used_file = "\n\nREM -------------------- " + filename + "---------------------" + "\n\n"
                Fill_section_bat.writelines(used_file)
                
                #Ecrit les infos dans le fichier .bat
                for i in range(nb_ligne):
                    if index_find[i] == 1 :
                        string_find[i] += " " + f + " " + directory_gen_fls + str(count_parse_elf) + mem_archi[i][2] + ".LUP\n"
                        #SREC: FOR DEBUG ONLY
                        #string_find[i] += " " + f + " " + f + "_sector" + str(i) + ".SREC\n"
                        Fill_section_bat.writelines(string_find[i])
            
            count_parse_elf = count_parse_elf + 1


    elif ELFBIN_PARSE == "BIN":
        if args.command :
            list_bin = directory_auto_elf
        else :
            list_bin = [os.path.join(directory_bin, filename) for filename in  os.listdir(directory_bin)]
    
        #List all file in the directory_bin
        print("\n Liste des fichie sources :")
        for f in list_bin:
            print(f)
            os.chmod( f, stat.S_IWRITE )
            os.chmod( directory_gen_fls, stat.S_IWRITE )
            os.chmod( directory_bin, stat.S_IWRITE )
            # checking if it is a file
            filename = os.path.basename(f)
            if os.path.isfile(f):
                bin_name_original = filename
                count_parse_bin = count_parse_bin + 1
                #if search(".ini", filename) or search(".sav", filename):
                #    print("continue")
                #    continue
                if count_parse_bin > 1 :
                    print(f)
                    log_bat_id.writelines(" /!\ ERROR : Un seul fichier doit être présent dans le dossier, nombre de fichier : au moins " + str(count_parse_bin))
                    print(" /!\ ERROR : Un seul fichier doit être présent dans le dossier, nombre de fichier : au moins " + str(count_parse_bin))
                    sys.exit() 
                print("\ncopie de {} vers {}".format(f,directory_gen_fls))
                shutil.copy2(f, directory_gen_fls)
            else :
                print("FILE does not exist : ", f)
                sys.exit()
    log_bat_id.close()


            
    #------------------------------------
    #|    BAT GENERATED : EXECUTE IT     |
    #------------------------------------
    print("Generate .bat")
    Fill_section_bat.close()
    call_script_bat = Extracted_bat_section
    subprocess.run(call_script_bat, stdout=subprocess.PIPE)
    #----------------------------
    #|    REMOVE EMPTY FILES     |
    #----------------------------

    for filename in os.listdir(directory_gen_fls):
        
        f = os.path.join(directory_gen_fls, filename)
        file2Remove = open(f, 'r', encoding="ISO-8859-1")
        
        text = file2Remove.read()
        
        file_stats = os.stat(file2Remove.name)
        if file_stats.st_size == text.count('\0'):
            file2Remove.close()
            os.remove(f)
        else :
            file2Remove.close()
    #---------------------------------
    #|    REMOVE DUPLICATED FILES     |
    #---------------------------------

    unique = dict()

    for filename in os.listdir(directory_gen_fls):
        f = os.path.join(directory_gen_fls, filename)
        if os.path.isfile(f):
            filehash = hashlib.md5(open(f, 'rb').read()).hexdigest()

            if filehash not in unique: 
                unique[filehash] = filename
            else:
                os.remove(f)     
    #---------------------------
    #|     CREATE .SUP FILE     |
    #---------------------------
    print("Generate sup_conf.ini file")          
    sup_file_path = os.path.join(directory_conf_fls, filename_sup)

    #.SUP HEADER#
    with open(sup_file_path, "w") as SUP_File:
        Header_SUP_lines = [ "[DEFAULT]\n", "; majeur/mineur\n", "version = 1\n", "onboardrunning = true\n", type_SUP, destination ,"; nom du fichier à adapter en fonction du nom dans le FLS.conf\n", "; adresse du LUP\n\n" ]
        SUP_File.writelines(Header_SUP_lines)

    #.SUP BODY#
    for filename in os.listdir(directory_gen_fls):

        adresse_SUP = "errorofscript"
        
        #if search(".ini", filename) or search(".sav", filename):
        #  continue
        #  continue
        
        
        if ELFBIN_PARSE == "ELF":
            for i in range(nb_ligne):
                if search(mem_archi[i][2], filename):
                        adresse_SUP = address_sector_SUP[i]
                        type_sup = type_sector_SUP[i]
                        
            with open(sup_file_path, "a") as SUP_File :
                Body_SUP_lines = [ "[" + str(filename) + "]\n", "; adresse du LUP\n", "address = " + str((hex(adresse_SUP))) +"\n", "; offset du point d'entrée dans le code par rapport au debut du LUP\n", "delta = 0x00000000\n", "encrypted = false\n", "name = ${load_pn}_" + str(filename) + "\n", type_sup + "\n\n" ]
                SUP_File.writelines(Body_SUP_lines)
                SUP_File.close()
        
        elif ELFBIN_PARSE == "BIN":
                adresse_SUP = adresse_SUP_in_BIN
                type_sup = "type = app"
                with open(sup_file_path, "a") as SUP_File :
                    Body_SUP_lines = [ "[" + str(filename) + "]\n", "; adresse du LUP\n", "address = " + str((hex(int(adresse_SUP,16)))) +"\n", "; offset du point d'entrée dans le code par rapport au debut du LUP\n", "delta = 0x00000000\n", "encrypted = false\n", "name = ${load_pn}_" + str(filename) + "\n", type_sup + "\n\n" ]
                    SUP_File.writelines(Body_SUP_lines)
                    SUP_File.close()
 
    #---------------------------
    #|     CREATE .SIF FILE     |
    #---------------------------
    print("Generate sif_conf.ini file")          
    sif_file_path = os.path.join(directory_conf_fls, filename_sif)

    #.SIF HEADER#
    with open(sif_file_path, "w") as SIF_File:
        Header_SIF_lines = [ "[DEFAULT]\n", SW_NAME_SIF, "path = . \n", "checks = SHA2-512\n\n", "[Targets]\n", "[FADEX_BOARD]\n", SIF_TARGET + "\n\n", "; ici on surcharge des valeurs par defaut\n", "; le nom correspond a ce qu'il y a dans le fichier SIF mais il peut etre different du vrai nom de fichier\n", "[Files]\n", SIF_FIRST_SIF ]
        SIF_File.writelines(Header_SIF_lines)

    #.SIF BODY#
    for filename in os.listdir(directory_gen_fls):
        
        #if search(".ini", filename) or search(".sav", filename):
        #  continue
        
        with open(sif_file_path, "a") as SIF_File:
            Body_SIF_lines = [ "[" + str(filename) + "]\n", "name = ${load_pn}_" + str(filename) + "\n\n" ]
            SIF_File.writelines(Body_SIF_lines)

    #.SIF FOOTER#
    with open(sif_file_path, "a") as SIF_File:
            Header_SIF_lines = [ "[APP.SUP]\n", "name = ${load_pn}.SUP\n\n", "[APP.CMP]\n", "name = ${load_pn}.CMP\n\n", lud_in_sif ]
            SIF_File.writelines(Header_SIF_lines)
            SIF_File.close()            
    #---------------------------
    #|     CREATE .LUH FILE     |
    #---------------------------
    print("Generate luh_conf.ini file")   
    luh_file_path = os.path.join(directory_conf_fls, filename_luh)

    #.LUH HEADER#
    with open(luh_file_path, "w") as LUH_File:
        Header_LUH_lines = [ "#***************************************************************\n", "#********************   G E N E R AL   *************************\n", "#***************************************************************\n", "#\n", "# MMMCC*YSSS*VVRR\n", "# MMM : SFI\n", "# YSSS : Y:\n", "#        1 for PU1 only\n", "#        2 is for PU2 only\n", "#        3 is for PU1 and PU2\n", "#        SSS:\n", "#        .001 (OSS_CU)\n", "#        .002 (CSS_CU)\n", "#        .003 (OSS_CONF_CU)\n", "#        .004 (CSS_CONF_CU)\n", "#        .005 (MCSS_CU)\n", "#        .006 (MCSS_CONF_CU)\n", "#        .007 (OLL)\n", "#        .008 (CERT_OLL)\n", "# CC : checksum 8bit\n", "# VVRR : version,revision SW\n", "#FLS_ID considered by the Calculator shall correspond to the YSSS: Software reference field\n\n", "[DEFAULT]\n", LOAD_PN_LUH, LOAD_ID, LOAD_DESCRIPTION, LUH_TARGET + "\n", "#***************************************************************\n", "#*************  T A R G E T _ W I T H _ P O S   ****************\n", "#***************************************************************\n", "# A665-3 ONLY\n", "[TARGET_WITH_POS]\n", LUH_TARGET, "positions               = L, R\n\n", "#***************************************************************\n", "#******************  D A T A _ F I L E S   *********************\n", "#***************************************************************\n", "#\n", "[DATA_FILES]\n", "default_data_files_path      = . \n\n" ]
        LUH_File.writelines(Header_LUH_lines)

    #.LUH BODY#
    #print( "recharche dans {}".format(directory_gen_fls))
    for filename in os.listdir(directory_gen_fls):
        print( "Fichier {}".format(filename))
        #if search(".ini", filename) or search(".sav", filename):
        #  continue
        
        with open(luh_file_path, "a") as LUH_File:
            Body_LUH_lines = [ "[" + str(filename) + "]\n", "pn = ${load_pn}\n", "name = ${load_pn}_" + str(filename) + "\n", "check = CRC32 \n", "\n" ]
            LUH_File.writelines(Body_LUH_lines)

    #.LUH FOOTER#
    with open(luh_file_path, "a") as LUH_File:
            Footer_LUH_lines = [ "#************************************************************************\n", "#******************  S U P P O R T _ F I L E S   *************\n", "#************************************************************************\n\n", "[SUPPORT_FILES]\n", "default_support_files_path   = . \n\n" , "[APP.SUP]\n", "pn = ${load_pn}\n", "name = ${load_pn}.SUP\n", "check = CRC32\n\n", "[APP.CMP]\n", "pn = ${load_pn}\n", "name = ${load_pn}.CMP\n", "check = CRC32\n\n", lud_in_luh, SIF_FIRST_LUH ]
            LUH_File.writelines(Footer_LUH_lines)
            LUH_File.close()              
    #---------------------------
    #|     CREATE .CMP FILE     |
    #---------------------------
    print("Generate cmp_conf.ini file")
    cmp_file_path = os.path.join(directory_conf_fls, filename_cmp)

    #.CMP HEADER#
    with open(cmp_file_path, "w") as CMP_File:
        Header_CMP_lines = [ "[DEFAULT]\n", "version = 1\n", SW_NAME_CMP ]
        CMP_File.writelines(Header_CMP_lines)

    #.CMP BODY#
    if FLS_NAME == "OSS_CU":
        with open(cmp_file_path, "a") as CMP_File:
                Body_CMP_lines = [ BOOT_CMP, MRAM_CMP, CSS_MCSS_CMP, HMOS_CMP, OSS_CONF_CMP ]
                CMP_File.writelines(Body_CMP_lines)
                CMP_File.close()
    else:
        with open(cmp_file_path, "a") as CMP_File:
                Body_CMP_lines = [ OSS_CU_CMP ]
                CMP_File.writelines(Body_CMP_lines)
                CMP_File.close()            
    #---------------------------
    #|     CREATE .LUD FILE     |
    #---------------------------
    print("Generate lud_conf.ini file")
    if lud_activated == 1:
        lud_file_path = os.path.join(directory_conf_fls, filename_lud)

        #.LUD BODY#
        with open(lud_file_path, "w") as LUD_File:
                Body_LUD_lines = [ MRAM_LUD, CSS_MCSS_LUD, OSS_CONF_LUD ]
                LUD_File.writelines(Body_LUD_lines)
                LUD_File.close()
    #-----------------------
    #|     CALL FLS_GEN     |
    #-----------------------
    print("Call @createFLS.exe")
    createFLS_exe = os.path.join(directory_bin_utils, "createFLS.exe")
    
#Modify .LOADGen caller depending on the FLASH_TYPE

    if FLS_LOADER == "OLL" :
        call_flsgen_bat = createFLS_exe + " -dp . -lpn " + LOAD_PN + " -c " + directory_conf_fls + " -mpn " + LOAD_PN + " -CA " + directory_certificates + "\DEV_ROOT_Certificate.pem -CAkey " + directory_certificates + "\DEV_ROOT_PrivateKey.pem --sign_luh -D FORCE_SIF_DOWNLOAD"
        
    elif FLS_LOADER == "T32" :
        call_flsgen_bat = createFLS_exe + " -dp . -lpn " + LOAD_PN + " -c " + directory_conf_fls + " -mpn " + LOAD_PN + " --bin --autosigned -D A665_NODATA_ADDR --SIFHEAD"
    
    genFLS_bat.writelines(call_flsgen_bat)
    genFLS_bat.close()
    
    subprocess.run(call_flsgen_bat, stdout=log_bat_fls, cwd=directory_gen_fls)
    log_bat_fls.close()
 
    #-----------------------
    #|     PRINT_SCRIPT     |
    #-----------------------

    if FLS_LOADER == "OLL" :
        print("Generate PHOENIX script")
        directory_script_gen = directory_script_gen + "\\PHOENIX\\"
        filename_script = "FADEX.phoenix"
        if not os.path.exists(directory_script_gen):
            os.makedirs(directory_script_gen)
    
    elif FLS_LOADER == "T32" :
        print("Generate T32 script")
        directory_script_gen = directory_script_gen + "\\T32\\"
        filename_script = "FADEX.cmm"
        flashbat_t32 = "flash_FLS.bat"
        if not os.path.exists(directory_script_gen):
            os.makedirs(directory_script_gen)
        
        flashcmm_bat_path = os.path.join(directory_script_gen, flashbat_t32)
        
    script_file_path = os.path.join(directory_script_gen, filename_script)      
    if FLS_LOADER == "OLL" :
        #.PHOENIX FILE#
        with open(script_file_path, "w") as PHOENIX_File:
            Phoenix_lines = [ "<PHOENIX_CONFIG>\n", "    <DEVICES>\n", "     <!-- Dataloader -->\n", "       <DEVICE PhysicalName=\"DATALOADER1\" ModuleDriver=\"ARINC615A.DLA.cDeviceArinc615aDLA, ARINC615A.DLA\" Wrapper=\"ARINC615A.Wrapper.cWrapperArinc615aDeviceMgt, ARINC615A.Wrapper\">\n", "           <TRANSPORT_LAYER>\n", "               <PARAM Name=\"LocalIP\" Value=\"10.0.0.99\" 	Description=\"Adresse IP Local\" />\n", "               <PARAM Name=\"LocalPort\" Value=\"3004\" 		Description=\"Port de communication Local\" />\n", "            <PARAM Name=\"NbRetry\" Value=\"3\" 			Description=\"Nombre d'essai\" />\n", "             <PARAM Name=\"BlockSize\" Value=\"8188\" 		Description=\"Taille de block en Octets\" />\n", "              <PARAM Name=\"Timeout_s\" Value=\"2\" 			Description=\"Time out en seconde\" />\n", "              <PARAM Name=\"MaxWaitFor_s\" Value=\"30\" 		Description=\"Temps attente max du calculateur\" />\n", "         <PARAM Name=\"A615Version\" Value=\"3\" 		Description=\"Version ARINC615A (2 = A3, 3 = A4)\" />\n", "           </TRANSPORT_LAYER>\n", "<HAL Name=\"TARGET\">\n", "               <PARAM Name=\"TargetName\" Value=\"SFI_EECFADEX_N\" 			Description=\"Nom de la cible\" />\n", "                <PARAM Name=\"TargetIP\" Value=\"10.0.0.1\" 				Description=\"Adresse IP de la cible\" />\n", "             <PARAM Name=\"TargetPort\" Value=\"59\" 						Description=\"Port de communication de la cible\" />\n", "                <PARAM Name=\"TempDirectory\" Value=\"C:\TEMP\DATALOADER\LOG\" 	Description=\"Dossier pour les fichiers de LOG\" />\n", "         </HAL>\n", "    </DEVICE>\n", " </DEVICES>\n", "    <!-- Master Name -->\n", "  <MASTERS>\n", "     </MASTERS>\n", "</PHOENIX_CONFIG>"]
            PHOENIX_File.writelines(Phoenix_lines)
            
    if FLS_LOADER == "T32" :
        T32_LAUT = directory_bin_utils + "T32\_LAUTERBACH\\"
        T32_TOOL = directory_bin_utils + "T32\Tools\\"
        
        #.BAT BODY#
        with open(flashcmm_bat_path, "w") as BATFLS_File:
            BAT_BODY = [ "@ECHO OFF\n", "CLS\n\n", "SET CUR_DIR=%~dp0\n\n", "CALL C:\T32\\bin\windows64\\t32mppc.exe -s %CUR_DIR%\FADEX.cmm" ]
            BATFLS_File.writelines(BAT_BODY)
        
        #.CMM HEADER#
        with open(script_file_path, "w") as CMM_File:
            CMM_Header = [ "RESET\n", "TOOLBAR ON\n", "STATUSBAR ON\n", "BREAK.RESET\n", "MODE.HLL\n", "DO " + T32_LAUT + "configuration_board.cmm\n", "DO " + T32_LAUT +"init_probe.cmm DEBUG_ON CPU_2\n", "DO "+ T32_LAUT + "init_board.cmm\n", "DO "+ T32_LAUT + "init_cpu.cmm\n", "do ~~/demo/powerpc/flash/jpc577xm.cmm prepareonly\n", "SYMBOL.RESET\n", "SYMBOL.SPATH.RESET\n", "SETUP.StepAllCores ON\n", "setup.var %Hex\n", "(\n", "flash.reprogram all\n\n" ]
            CMM_File.writelines(CMM_Header)
            
        #.CMM BODY#
        directory_gen_lup = directory_gen_fls + LOAD_PN + "\\" + LOAD_PN + "\\"
        directory_gen_bin = directory_gen_fls + LOAD_PN + "\\"
        directory_gen_sifhc = directory_gen_fls
        
        if ELFBIN_PARSE == "BIN":
            bin_name_original = LOAD_PN + "_" + bin_name_original
        
        for filename in os.listdir(directory_gen_lup):
        
            adresse_SUP = "errorofscript"
            
            if ELFBIN_PARSE == "ELF":
                if search(".LUP", filename) :
                    for i in range(nb_ligne):
                        if search(mem_archi[i][2], filename):
                                adresse_SUP = address_sector_SUP[i]
                                
                    with open(script_file_path, "a") as CMM_File :
                        CMM_Body = [ "Data.LOAD.Binary " + directory_gen_lup + filename + " " + str(hex(adresse_SUP)) + " /STRIPPATH /NOCLEAR \n" ]
                        CMM_File.writelines(CMM_Body)
                        
            elif ELFBIN_PARSE == "BIN":
                if bin_name_original == filename :
                    adresse_SUP = adresse_SUP_in_BIN
                    with open(script_file_path, "a") as CMM_File :
                        CMM_Body = [ "Data.LOAD.Binary " + directory_gen_lup + filename + " " + str((hex(int(adresse_SUP,16)))) + " /STRIPPATH /NOCLEAR \n" ]
                        CMM_File.writelines(CMM_Body)
                        CMM_File.close()
                        
        with open(script_file_path, "a") as CMM_File :
            CMM_Body = [ "Data.LOAD.Binary " + directory_gen_sifhc + LOAD_PN + ".SIFHC" + " " + str(hex(adresse_SIFHC)) + " /STRIPPATH /NOCLEAR \n" ]
            CMM_File.writelines(CMM_Body)
        
        with open(script_file_path, "a") as CMM_File :
            CMM_Body = [ "Data.LOAD.Binary " + directory_gen_bin + LOAD_PN + ".bin" + " " + str(hex(adresse_BIN)) + " /STRIPPATH /NOCLEAR \n" ]
            CMM_File.writelines(CMM_Body)
        
        #.CMM FOOTER#
        with open(script_file_path, "a") as CMM_File:
            CMM_Footer = [ "\nflash.reprogram off\n", ")\n", "; End of Script\n", ";ENDDO\n\n" ]
            CMM_File.writelines(CMM_Footer)
    # Remove unecessary redondant files      
    print("----- Suppression des fichiers Redondant -----")
    for file in os.listdir(directory_gen_fls) :
        if os.path.isfile(os.path.join(directory_gen_fls, file)) :
            try :
                os.remove(os.path.join(directory_gen_fls, file))
            except Exception as E :
                print(E)
                print(f'CANNOT DELETE {directory_gen_fls}\\{file}')
    print("----- FLS Generation done ! -----")