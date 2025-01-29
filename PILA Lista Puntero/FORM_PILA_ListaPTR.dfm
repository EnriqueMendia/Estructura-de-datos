object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
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
    Caption = 'Crear Pila'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 0
    Top = 48
    Width = 120
    Height = 25
    Caption = 'Poner Pila'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 88
    Width = 120
    Height = 25
    Caption = 'Mostrar Pila'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 128
    Width = 120
    Height = 25
    Caption = 'Salir'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 240
    Width = 120
    Height = 25
    Caption = 'Mostrar Lista'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 49
    Width = 121
    Height = 23
    TabOrder = 5
    TextHint = 'elem...'
  end
end
