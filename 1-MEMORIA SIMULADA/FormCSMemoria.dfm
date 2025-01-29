object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 641
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 0
    Top = 16
    Width = 100
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 0
    Top = 98
    Width = 100
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 57
    Width = 100
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 136
    Width = 100
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 176
    Width = 100
    Height = 25
    Caption = 'Poner Dato'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 120
    Top = 58
    Width = 100
    Height = 23
    TabOrder = 5
    TextHint = 'cadena: x,y,z'
  end
  object Edit2: TEdit
    Left = 120
    Top = 99
    Width = 100
    Height = 23
    TabOrder = 6
    TextHint = 'dir...'
  end
  object Edit3: TEdit
    Left = 120
    Top = 137
    Width = 80
    Height = 23
    TabOrder = 7
    Text = '0'
    TextHint = 'desde..'
  end
  object Edit4: TEdit
    Left = 216
    Top = 137
    Width = 80
    Height = 23
    TabOrder = 8
    Text = '30'
    TextHint = 'hasta..'
  end
  object Edit5: TEdit
    Left = 120
    Top = 177
    Width = 80
    Height = 23
    TabOrder = 9
    TextHint = 'dir...'
  end
  object Edit6: TEdit
    Left = 216
    Top = 177
    Width = 80
    Height = 23
    TabOrder = 10
    TextHint = '->ID'
  end
  object Edit7: TEdit
    Left = 312
    Top = 177
    Width = 80
    Height = 23
    TabOrder = 11
    TextHint = 'valor..'
  end
end
