object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 738
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 0
    Top = 8
    Width = 150
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 0
    Top = 48
    Width = 150
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 88
    Width = 150
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 127
    Width = 150
    Height = 25
    Caption = 'Crear Matriz'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 168
    Width = 150
    Height = 25
    Caption = 'Dimensionar Matriz'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 0
    Top = 208
    Width = 150
    Height = 25
    Caption = 'Asignar Valor Por Defecto'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 0
    Top = 248
    Width = 150
    Height = 25
    Caption = 'Poner Dato'
    TabOrder = 6
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 0
    Top = 289
    Width = 150
    Height = 25
    Caption = 'Mostrar Matriz'
    TabOrder = 7
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 0
    Top = 408
    Width = 150
    Height = 25
    Caption = 'Salir'
    TabOrder = 8
    OnClick = Button9Click
  end
  object Edit1: TEdit
    Left = 168
    Top = 49
    Width = 70
    Height = 23
    TabOrder = 9
    TextHint = 'ej,em,plo'
  end
  object Edit2: TEdit
    Left = 168
    Top = 89
    Width = 70
    Height = 23
    TabOrder = 10
    TextHint = 'dir...'
  end
  object Edit3: TEdit
    Left = 168
    Top = 169
    Width = 70
    Height = 23
    TabOrder = 11
    TextHint = 'Filas...'
  end
  object Edit4: TEdit
    Left = 256
    Top = 169
    Width = 70
    Height = 23
    TabOrder = 12
    TextHint = 'Cols...'
  end
  object Edit5: TEdit
    Left = 168
    Top = 209
    Width = 70
    Height = 23
    TabOrder = 13
    TextHint = 'valor..'
  end
  object Edit6: TEdit
    Left = 168
    Top = 249
    Width = 70
    Height = 23
    TabOrder = 14
    TextHint = 'fila..'
  end
  object Edit7: TEdit
    Left = 256
    Top = 249
    Width = 70
    Height = 23
    TabOrder = 15
    TextHint = 'col...'
  end
  object Edit8: TEdit
    Left = 344
    Top = 249
    Width = 70
    Height = 23
    TabOrder = 16
    TextHint = 'valor..'
  end
  object Button10: TButton
    Left = 0
    Top = 327
    Width = 150
    Height = 25
    Caption = 'Verifica Sudoku'
    TabOrder = 17
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 0
    Top = 367
    Width = 150
    Height = 25
    Caption = 'Retroceder en poner'
    TabOrder = 18
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 168
    Top = 327
    Width = 121
    Height = 25
    Caption = 'Sudokear'
    TabOrder = 19
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 168
    Top = 289
    Width = 121
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 20
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 168
    Top = 127
    Width = 121
    Height = 25
    Caption = 'Crear Pila'
    TabOrder = 21
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 168
    Top = 367
    Width = 121
    Height = 25
    Caption = 'Backtrack'
    TabOrder = 22
    OnClick = Button15Click
  end
end
