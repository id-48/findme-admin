import 'package:country_code_picker/country_code_picker.dart';
import 'package:find_me_admin/models/places/res_get_all_place.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/models/designing/add_designing/req_designing.dart';
import 'package:find_me_admin/models/designing/get_designing/res_desinging.dart';
import 'package:find_me_admin/models/designing/update_designing/req_update_desinging.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/get_all_places.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';

import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Constants.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/constants.dart';
import '../../utils/Extensions/text_styles.dart';

class AddPlacesDialog extends StatefulWidget {
  static String tag = '/AddPlace';

  final Place? placeData;
  final Function()? onUpdate;

  AddPlacesDialog({this.onUpdate, this.placeData});

  @override
  State<AddPlacesDialog> createState() => _AddPlacesDialogState();
}

class _AddPlacesDialogState extends State<AddPlacesDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();
  String pickupCountryCode = defaultPhoneCode;

  TextEditingController placeNameCon = TextEditingController();
  TextEditingController categoryCon = TextEditingController();
  TextEditingController addLocationCon = TextEditingController();
  TextEditingController latitudeCon = TextEditingController();
  TextEditingController longitudeCon = TextEditingController();
  TextEditingController locatedWithin = TextEditingController();
  TextEditingController placeDescriptionCon = TextEditingController();
  TextEditingController monoController = TextEditingController();

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.placeData != null;

    if (isUpdate) {
      placeNameCon.text =
      widget.placeData!.placeName.isNotEmpty ? widget.placeData!.placeName : "";
      categoryCon.text =
      widget.placeData!.category.isNotEmpty ? widget.placeData!.category : "";
      addLocationCon.text =
      widget.placeData!.location.isNotEmpty ? widget.placeData!.location : "";
      latitudeCon.text =
      widget.placeData!.lattitued.isNotEmpty ? widget.placeData!.lattitued : "";
      longitudeCon.text = widget.placeData!.longtitude.isNotEmpty
          ? widget.placeData!.longtitude
          : "";
      locatedWithin.text =
      widget.placeData!.locatedWithin.isNotEmpty ? widget.placeData!
          .locatedWithin : "";
      placeDescriptionCon.text =
      widget.placeData!.placeDescription.isNotEmpty ? widget.placeData!
          .placeDescription : "";
      monoController.text =
      widget.placeData!.mono.isNotEmpty ? widget.placeData!.mono : "";
    }
  }

  AddPlaceApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      var data = {
        "placeName": placeNameCon.text.trim(),
        "category": categoryCon.text.trim(),
        "location": addLocationCon.text.trim(),
        "lattitued": latitudeCon.text.trim(),
        "longtitude": longitudeCon.text.trim(),
        "locatedWithin": locatedWithin.text.trim(),
        "placeDescription": placeDescriptionCon.text.trim(),
        "mono": monoController.text.trim()
      };
      await addPlaceData(req: data).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");

          Navigator.pushNamed(context, GetAllPlacesScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  UpdatePlaceDataApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      var data = {
        "placeId": widget.placeData!.id.trim(),
        "placeName": placeNameCon.text.trim(),
        "category": categoryCon.text.trim(),
        "location": addLocationCon.text.trim(),
        "lattitued": latitudeCon.text.trim(),
        "longtitude": longitudeCon.text.trim(),
        "locatedWithin": locatedWithin.text.trim(),
        "placeDescription": placeDescriptionCon.text.trim(),
        "mono": monoController.text.trim(),
      };

      await updatePlaceData(req: data).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          Navigator.pushNamed(context, GetAllPlacesScreen.route);
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
          Text(isUpdate ? "Update Place Details" : "Add Place Details",
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
                        Text("Place Name", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: placeNameCon,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Category ", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: categoryCon,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Location", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          // readOnly: true,
                          controller: addLocationCon,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Latitude", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: latitudeCon,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Longitude", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: longitudeCon,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Location within", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: locatedWithin,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Place description", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: placeDescriptionCon,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Mobile Number", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: monoController,
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
                                            borderSide: BorderSide(color: Theme
                                                .of(context)
                                                .dividerColor)),
                                        focusedBorder:
                                        UnderlineInputBorder(
                                            borderSide: BorderSide(
                                                color: primaryColor)),
                                      ),
                                      searchStyle: primaryTextStyle(),
                                      onInit: (c) {
                                        pickupCountryCode = c!.dialCode!;
                                      },
                                      onChanged: (c) {
                                        pickupCountryCode = c.dialCode!;
                                      },
                                    ),
                                    VerticalDivider(
                                        color: Colors.grey.withOpacity(0.5)),
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
          isUpdate ? UpdatePlaceDataApi() : AddPlaceApi();
        }),
      ],
    );
  }
}
