object CyliReflFm: TCyliReflFm
  Left = 7
  Top = 108
  Width = 800
  Height = 573
  Caption = 'Модель фокусирующего коллектора с цилиндрическим отражателем'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 552
    Top = 472
    Width = 73
    Height = 17
    Caption = 'Стоп'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 432
    Top = 472
    Width = 65
    Height = 17
    Caption = 'Пуск'
    TabOrder = 1
    OnClick = Button2Click
  end
  object DateTimePicker: TDateTimePicker
    Left = 592
    Top = 8
    Width = 186
    Height = 32
    CalAlignment = dtaLeft
    Date = 36699.3820086806
    Time = 36699.3820086806
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 2
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
    Left = 8
    Top = 8
  end
end
