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
  object Button4: TButton
    Left = 0
    Top = 8
    Width = 120
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 0
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 48
    Width = 120
    Height = 25
    Caption = 'Poner Termino'
    TabOrder = 1
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 0
    Top = 88
    Width = 120
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
  end
  object Button7: TButton
    Left = 0
    Top = 128
    Width = 120
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
  end
  object Button9: TButton
    Left = 0
    Top = 208
    Width = 120
    Height = 25
    Caption = 'Mostrar Polinomio'
    TabOrder = 4
    OnClick = Button9Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 49
    Width = 70
    Height = 23
    TabOrder = 5
    TextHint = 'coef...'
  end
  object Edit2: TEdit
    Left = 212
    Top = 49
    Width = 70
    Height = 23
    TabOrder = 6
    TextHint = 'exp...'
  end
end
