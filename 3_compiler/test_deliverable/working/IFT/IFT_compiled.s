     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
$LFB0          = .
     .align    2         
     .globl    iftrue    
     .set      nomips16  
     .set      nomicromips
     .ent      iftrue    
     .type     iftrue,   @function
iftrue:
     .frame    $fp,16,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-16
     sw        $fp,12($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
     li          $2,6
     sw          $2,4($fp)
     lw          $2,4($fp)
     slt         $2,$2,13
     beq         $2,$0,$L2
     nop       

     move        $2,$0
     b          $L3
     nop       

$L2:
     li          $2,1
     b          $L3
     nop       

$L3:
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,12($sp)
     addiu     $sp,$sp,16
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      iftrue    
     .size     iftrue, .-iftrue
