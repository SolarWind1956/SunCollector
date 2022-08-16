object MidTimFm: TMidTimFm
  Left = 21
  Top = 121
  Width = 644
  Height = 288
  Caption = 'Время истинного подня'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -24
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 29
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 162
    Height = 20
    Caption = 'Истинный полдень'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 288
    Top = 96
    Width = 93
    Height = 20
    Caption = 'Перигелий'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 288
    Top = 136
    Width = 218
    Height = 20
    Caption = 'Весеннее равноденствие'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 288
    Top = 176
    Width = 89
    Height = 20
    Caption = 'День года'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object WinterTagRGrp: TRadioGroup
    Left = 8
    Top = 88
    Width = 265
    Height = 105
    Caption = 'Признак сезона (Зима/лето)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemIndex = 1
    Items.Strings = (
      'Лето'
      'Зима')
    ParentFont = False
    TabOrder = 0
    OnClick = WinterTagRGrpClick
  end
  object TrueMiddTimeME: TMaskEdit
    Left = 208
    Top = 16
    Width = 137
    Height = 37
    AutoSelect = False
    EditMask = '!90:00:00>;1;_'
    MaxLength = 8
    ReadOnly = True
    TabOrder = 1
    Text = '  :  :  '
  end
  object DateTimePicker: TDateTimePicker
    Left = 432
    Top = 16
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
    OnChange = DateTimePickerChange
  end
  object PerEdit: TEdit
    Left = 432
    Top = 87
    Width = 49
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
  end
  object DayOfYearEdit: TEdit
    Left = 432
    Top = 173
    Width = 41
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object VernalEquinoxDayEdit: TEdit
    Left = 520
    Top = 129
    Width = 49
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
end
