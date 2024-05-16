import 'package:country_code_picker/country_code_picker.dart';
import 'package:date_time_picker/date_time_picker.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/get_all_events.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';
import '../../main.dart';
import '../../models/event/get_user_wise_event/res_get_user_wise_event.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Constants.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/constants.dart';
import '../../utils/Extensions/text_styles.dart';

class AddEventDialog extends StatefulWidget {
  static String tag = '/AddEventDialog';

  final Event? event;
  final Function()? onUpdate;

  AddEventDialog({this.onUpdate, this.event});

  @override
  State<AddEventDialog> createState() => _AddEventDialogState();
}

class _AddEventDialogState extends State<AddEventDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();
  String pickupCountryCode = defaultPhoneCode;

  TextEditingController titleCont = TextEditingController();
  TextEditingController locationCont = TextEditingController();
  TextEditingController lattitudeCont = TextEditingController();
  TextEditingController longtitudeCont = TextEditingController();
  TextEditingController eventDateCont = TextEditingController();
  TextEditingController timeCont = TextEditingController();
  TextEditingController descriptionCont = TextEditingController();
  TextEditingController monoCont = TextEditingController();

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.event != null;

    if (isUpdate) {
      titleCont.text = widget.event!.title;
      locationCont.text = widget.event!.location;
      lattitudeCont.text = widget.event!.lattitude;
      longtitudeCont.text = widget.event!.longtitude;
      eventDateCont.text = widget.event!.eventDate.toIso8601String();
      timeCont.text = widget.event!.time;
      descriptionCont.text = widget.event!.description;
      monoCont.text = widget.event!.mono;
    }
  }

  AddEventApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      Map<String, dynamic> data = {
        "title": titleCont.text.trim().toString(),
        "location": locationCont.text.trim().toString(),
        "lattitude": lattitudeCont.text.trim().toString(),
        "longtitude": longtitudeCont.text.trim().toString(),
        "eventDate": eventDateCont.text.trim().toString(),
        "time": timeCont.text.trim().toString(),
        "description": descriptionCont.text.trim().toString(),
        "mono": monoCont.text.trim().toString(),
      };
      print('reqAddEvent ::${data.toString()}');
      await addEvent(req: data).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");

          Navigator.pushNamed(context, GetAllEventsScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  UpdateEventApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      Map<String, dynamic> data = {
        "eventId": widget.event!.id.trim(),
        "title": titleCont.text.trim().toString(),
        "location": locationCont.text.trim().toString(),
        "lattitude": lattitudeCont.text.trim().toString(),
        "longtitude": longtitudeCont.text.trim().toString(),
        "eventDate": eventDateCont.text.trim().toString(),
        "time": timeCont.text.trim().toString(),
        "description": descriptionCont.text.trim().toString(),
        "mono": monoCont.text.trim().toString(),
      };
      print('reqUpdateEvent :::${data.toString()}');
      await updateEvent(req: data).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          Navigator.pushNamed(context, GetAllEventsScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      actionsPadding: EdgeInsets.only(right: 16, bottom: 16),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(isUpdate ? "Update Event Details" : "Add Event Details",
              style: boldTextStyle(color: primaryColor, size: 20)),
          IconButton(
            icon: Icon(Icons.close),
            padding: EdgeInsets.zero,
            onPressed: () {
              Navigator.pop(context, false);
            },
          ),
        ],
      ),
      content: Observer(builder: (context) {
        return SingleChildScrollView(
          child: Stack(
            children: [
              Visibility(
                visible: !appStore.isLoading,
                child: Form(
                  key: _formKey,
                  child: SizedBox(
                    width: ResponsiveWidget.isMediumScreen(context)
                        ? getBodyWidth(context)
                        : (getBodyWidth(context) - 48) * 0.4,
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Title", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: titleCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Location", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: locationCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Mobile Number",
                                      style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: monoCont,
                                    textInputAction: TextInputAction.next,
                                    textFieldType: TextFieldType.PHONE,
                                    maxLength: 10,
                                    decoration: commonInputDecoration(
                                        suffixIcon: Icon(Icons.phone),
                                        prefixIcon: IntrinsicHeight(
                                          child: Row(
                                            mainAxisSize: MainAxisSize.min,
                                            children: [
                                              CountryCodePicker(
                                                initialSelection: pickupCountryCode,
                                                showCountryOnly: false,
                                                showFlag: true,
                                                showFlagDialog: true,
                                                showOnlyCountryWhenClosed: false,
                                                alignLeft: false,
                                                textStyle: primaryTextStyle(),
                                                dialogBackgroundColor: Theme
                                                    .of(context)
                                                    .cardColor,
                                                barrierColor: Colors.black12,
                                                dialogTextStyle: primaryTextStyle(),
                                                searchDecoration: InputDecoration(
                                                  iconColor: Theme
                                                      .of(context)
                                                      .dividerColor,
                                                  enabledBorder: UnderlineInputBorder(
                                                      borderSide: BorderSide(
                                                          color: Theme
                                                              .of(context)
                                                              .dividerColor)),
                                                  focusedBorder:
                                                  UnderlineInputBorder(
                                                      borderSide: BorderSide(
                                                          color: primaryColor)),
                                                ),
                                                searchStyle: primaryTextStyle(),
                                                onInit: (c) {
                                                  pickupCountryCode =
                                                  c!.dialCode!;
                                                },
                                                onChanged: (c) {
                                                  pickupCountryCode =
                                                  c.dialCode!;
                                                },
                                              ),
                                              VerticalDivider(color: Colors.grey
                                                  .withOpacity(0.5)),
                                            ],
                                          ),
                                        )),
                                    validator: (value) {
                                      if (value!.trim().isEmpty) {
                                        return errorThisFieldRequired;
                                      } else if (value
                                          .trim()
                                          .length != 10) {
                                        return error10digit;
                                      }
                                      return null;
                                    },
                                    inputFormatters: [
                                      FilteringTextInputFormatter.digitsOnly,
                                    ],
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Longitude", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: longtitudeCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: 10),
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Latitude", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: lattitudeCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Date", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  DateTimePicker(
                                    controller: eventDateCont,
                                    type: DateTimePickerType.date,
                                    dateMask: "dd/MM/yyyy",
                                    lastDate: DateTime(2100),
                                    firstDate: DateTime(2010),
                                    onChanged: (value) {
                                      setState(() {});
                                    },
                                    decoration:
                                    commonInputDecoration(
                                        suffixIcon: Icon(Icons.date_range),
                                        hintText: "Date"),
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: 10),
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Time", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: timeCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text(
                                      "Description", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: descriptionCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                      ],
                    ),
                  ),
                ),
              ),
              Visibility(visible: appStore.isLoading, child: loaderWidget()),
            ],
          ),
        );
      }),
      actions: <Widget>[
        dialogSecondaryButton("Cancel", () {
          Navigator.pop(context, false);
        }),
        SizedBox(width: 4),
        dialogPrimaryButton(isUpdate ? "Update" : "Add", () {
          isUpdate ? UpdateEventApi() : AddEventApi();
        }),
      ],
    );
  }
}
