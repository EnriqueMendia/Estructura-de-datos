object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 477
  ClientWidth = 624
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
    Width = 120
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 0
    Top = 48
    Width = 120
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 88
    Width = 120
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 128
    Width = 120
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 168
    Width = 120
    Height = 25
    Caption = 'Poner Termino'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 0
    Top = 208
    Width = 120
    Height = 25
    Caption = 'Mostrar Polinomio'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 0
    Top = 248
    Width = 120
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 6
    OnClick = Button7Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 49
    Width = 100
    Height = 23
    TabOrder = 7
    TextHint = 'x,y,z'
  end
  object Edit2: TEdit
    Left = 136
    Top = 89
    Width = 100
    Height = 23
    TabOrder = 8
    TextHint = 'dir...'
  end
  object Edit3: TEdit
    Left = 136
    Top = 169
    Width = 70
    Height = 23
    TabOrder = 9
    TextHint = 'coef...'
  end
  object Edit4: TEdit
    Left = 224
    Top = 169
    Width = 70
    Height = 23
    TabOrder = 10
    TextHint = 'exp...'
  end
  object Button8: TButton
    Left = 0
    Top = 288
    Width = 120
    Height = 25
    Caption = 'DERIVAR'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 0
    Top = 328
    Width = 120
    Height = 25
    Caption = 'EVALUAR'
    TabOrder = 12
    OnClick = Button9Click
  end
  object Edit5: TEdit
    Left = 136
    Top = 329
    Width = 70
    Height = 23
    TabOrder = 13
    TextHint = 'valor..'
  end
  object Button10: TButton
    Left = 0
    Top = 368
    Width = 120
    Height = 25
    Caption = 'Graficar Polinomio'
    TabOrder = 14
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 0
    Top = 408
    Width = 120
    Height = 25
    Caption = 'INTERSECTAR'
    TabOrder = 15
    OnClick = Button11Click
  end
end
