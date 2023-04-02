# How to update your TTP projet

To launch the TTP project update on your favorite CSCI, just follow these steps :
- Remove the read-only flag on the **\[CSCI\]_dev** (especially on **\[CSCI\]_dev/reports/Coding_standard/**)
- Use python 3.8 (or upper) to run the script. No argument required :
    ```py
    python updateTTP.py
    ```
- If another **CSC** folder has been added to the **\[CSCI\]_dev** directory, make sure to add the correct include path to the **\[CSCI\]_dev/reports/\[CSCI\].def** file.

That's all folks !