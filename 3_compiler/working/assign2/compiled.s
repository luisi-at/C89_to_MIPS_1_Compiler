     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
RETURN NAME DIRECT DEC EMPTY
RETURN NAME IDENTIFIER DECLARATOR
RETURN NAME IDENTIFIER EXPRESSION
NAME--> function
     .align    2         
     .globl    NAME      
     .set      nomips16  
     .set      nomicromips
     .ent      FUNCTION NAME
     .type     FUNCTION NAME, @function
RETURN NAME DIRECT DEC EMPTY
RETURN NAME IDENTIFIER DECLARATOR
RETURN NAME IDENTIFIER EXPRESSION
NAME--> main
     .align    2         
     .globl    NAME      
     .set      nomips16  
     .set      nomicromips
     .ent      FUNCTION NAME
     .type     FUNCTION NAME, @function
