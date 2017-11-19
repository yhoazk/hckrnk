# cobool

Unser Cobol-Entwickler ist krank und wir müssen den Vermittlern dringend die Provisionen auszahlen. Schaffst du es die Summe der Provisionen zu berechnen? Hier sind die Input Dateien.

```cobol
IDENTIFICATION DIVISION.
PROGRAM-ID.    PAUSZ.
AUTHOR.                 NONE
    INSTALLATION.       NONE
    DATE WRITTEN.       26.02.1984.
    DATE COMPILED.

ENVIRONMENT DIVISION.
CONFIGURATION SECTION.
SPECIAL-NAMES.
    DECIMAL-POINT IS COMMA.

INPUT-OUTPUT SECTION.
FILE-CONTROL.
      SELECT PROVIN  ASSIGN DDPIN
                     ORGANIZATION SEQUENTIAL.
      SELECT VET    ASSIGN DDVERS
                     ORGANIZATION SEQUENTIAL.
      SELECT PROVOUT ASSIGN DDPOUT
                     ORGANIZATION SEQUENTIAL.

DATA DIVISION.
FILE SECTION.
FD  PROVIN
    RECORDING F
    LABEL RECORD STANDARD
    BLOCK 0 RECORDS.
01 PROVIN-DATA.
 03         AV-DATEN.
  05        AV-NR          PIC X(10).
  05        AV-EP          PIC S9V9(04)     COMP-3.
  05        AV-BP          PIC S9V9(04)     COMP-3.
 03         VE-DATEN.
  05        VE-NR          PIC  X(12).
  05        VE-TYP         PIC  X(06).
  05        VE-JB          PIC S9(09)V99    COMP-3.
  05        VE-LZ          PIC S9(05)       COMP-3.

FD  VET
    RECORDING F
    LABEL RECORD STANDARD
    BLOCK 0 RECORDS.
01 VET-DATEN.
  05        VET-TYP        PIC X(6).
  05        VET-BPRZ       PIC S9V9(04)     COMP-3.
  05        VET-MLZ        PIC S9(05)       COMP-3.

FD  PROVOUT
    RECORDING F
    LABEL RECORD STANDARD
    BLOCK 0 RECORDS.
01 PR-DATEN.
 03         PR-AV-NR       PIC X(10).
 03         PR-VE-NR       PIC X(12).
 03         PR-BNR.
  05        PR-BNR-JAHR    PIC X(4).
  05        PR-BNR-MONAT   PIC X(2).
  05        PR-BNR-TAG     PIC X(2).
  05        PR-BNR-LFNR    PIC X(4).
 03         PR-SUMME       PIC X(13).

WORKING-STORAGE SECTION.
01 DAT                     PIC X(21).
01 DAT-X REDEFINES DAT.
 03         JAHR           PIC 9(4).
 03         MONAT          PIC 9(2).
 03         TAG            PIC 9(2).
 03         REST           PIC X(13).

01 PROVIN-EOF              PIC X(01) VALUE 'N'.
01 VET-EOF                 PIC X(01) VALUE 'N'.

01 Z-VET-BPRZ              PIC S9V9(04)    COMP-3.
01 Z-VET-MLZ               PIC S9(05)       COMP-3.

01 Z-AV-NR                 PIC X(10) VALUE '0000000000'.
01 Z-LFNR                  PIC 9(04) VALUE 0.
01 Z-PR-SUMME              PIC -9(09),99.

01 Z-VET-DATEN.
 03         VET-X OCCURS 1000 INDEXED BY VET-IND.
  05        VET-X-TYP      PIC X(6).
  05        VET-X-BPRZ     PIC S9V9(04)    COMP-3.
  05        VET-X-MLZ      PIC S9(05)       COMP-3.

PROCEDURE DIVISION.
    MOVE FUNCTION CURRENT-DATE TO DAT.

    OPEN INPUT PROVIN.
    OPEN INPUT VET.
    OPEN OUTPUT PROVOUT.


    PERFORM VARYING VET-IND FROM 1 BY 1
              UNTIL VET-EOF = 'Y'
       READ VET INTO VET-X(VET-IND)
          AT END MOVE 'Y' TO VET-EOF
       END-READ
    END-PERFORM.

    READ PROVIN
       AT END MOVE 'Y' TO PROVIN-EOF
    END-READ

    PERFORM UNTIL PROVIN-EOF = 'Y'
       IF AV-NR NOT = Z-AV-NR
          MOVE 1 TO Z-LFNR
          MOVE AV-NR TO Z-AV-NR
       ELSE
          ADD 1 TO Z-LFNR
       END-IF

       SET VET-IND TO 1
       SEARCH VET-X VARYING VET-IND
          WHEN VET-X-TYP(VET-IND) = VE-TYP
             MOVE VET-X-BPRZ(VET-IND) TO Z-VET-BPRZ
             MOVE VET-X-MLZ(VET-IND)   TO Z-VET-MLZ
       END-SEARCH

       MOVE 0 TO Z-PR-SUMME
       IF VE-LZ = 1
          COMPUTE Z-PR-SUMME ROUNDED = VE-JB * AV-EP * Z-VET-BPRZ
       END-IF
       IF VE-LZ <= VET-MLZ AND VE-LZ > 1
          COMPUTE Z-PR-SUMME ROUNDED = VE-JB * AV-BP * Z-VET-BPRZ
       END-IF

       MOVE AV-NR       TO PR-AV-NR
       MOVE VE-NR       TO PR-VE-NR
       MOVE JAHR        TO PR-BNR-JAHR
       MOVE MONAT       TO PR-BNR-MONAT
       MOVE TAG         TO PR-BNR-TAG
       MOVE Z-LFNR      TO PR-BNR-LFNR
       MOVE Z-PR-SUMME  TO PR-SUMME
       WRITE PR-DATEN

       READ PROVIN
          AT END MOVE 'Y' TO PROVIN-EOF
       END-READ
    END-PERFORM.

    CLOSE PROVIN.
    CLOSE VET.
    CLOSE PROVOUT.

    STOP RUN.

```
