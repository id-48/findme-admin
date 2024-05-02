import 'package:country_code_picker/country_code_picker.dart';
import 'package:file_selector/file_selector.dart';
import 'package:find_me_admin/models/user_model/get_user_profile.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/models/showroom/add_showroom/req_add_showroom.dart';
import 'package:find_me_admin/models/showroom/get_showroom/res_get_showroom.dart';
import 'package:find_me_admin/models/showroom/update_showroom/req_update_showroom.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/get_users_screen.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';
import 'package:image_picker/image_picker.dart';

import '../../main.dart';
import '../../models/user_model/res_get_all_user.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Constants.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/colors.dart';
import '../../utils/Extensions/text_styles.dart';
import '../../widget/selected_image_viewer.dart';

class AddUserDialog extends StatefulWidget {
  static String tag = '/AddUserDialog';

  final AllUser? userData;
  final Function()? onUpdate;

  AddUserDialog({this.onUpdate, this.userData});

  @override
  State<AddUserDialog> createState() => _AddUserDialogState();
}

class _AddUserDialogState extends State<AddUserDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController firstNameCont = TextEditingController();
  TextEditingController lastNameCont = TextEditingController();
  TextEditingController userNameCont = TextEditingController();
  TextEditingController monoCont = TextEditingController();
  TextEditingController addressCont = TextEditingController();
  TextEditingController lattitudeCont = TextEditingController();
  TextEditingController longtitudeCont = TextEditingController();
  TextEditingController countryNameCont = TextEditingController();
  TextEditingController countryCodeCont = TextEditingController();
  XFile? imageXFile;
  Uint8List? imgUint8list;
  String pickupCountryCode = defaultPhoneCode;

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.userData != null;

    if (isUpdate) {
      // firstNameCont.text = widget.userData!.firstName.validate();
      // lastNameCont.text = widget.userData!.lastName.validate();
      userNameCont.text = widget.userData!.name.validate();
      monoCont.text = widget.userData!.mono.validate();
      // addressCont.text = widget.userData!.validate();
      lattitudeCont.text = widget.userData!.lattitude.toString().validate();
      longtitudeCont.text = widget.userData!.longtitude.toString().validate();
      // countryNameCont.text = widget.userData!.countryName.validate();
      countryCodeCont.text = widget.userData!.countryCode.validate();

      print('widget.userData!.profilePic:::${widget.userData!.profilePic
          .toString()}');
      if (widget.userData!.profilePic.isNotEmpty) {
        imgUint8list = await imageDataURLtoUint8List(
            mBaseUrl + widget.userData!.profilePic[0]);
        print('imgUint8list :::${imgUint8list.toString()}');
      }
      setState(() {});
    }
  }

  Future<void> getImage() async {
    imageXFile = await ImagePicker().pickImage(source: ImageSource.gallery);

    if (imageXFile!.path.isNotEmpty) {
      Uint8List image = await imageXFile!.readAsBytes();
      imgUint8list = image;
      setState(() {});
    }
  }

  AddUser() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      String firstName = firstNameCont.text.trim();
      String lastName = lastNameCont.text.trim();
      String userName = userNameCont.text.trim();
      String mono = monoCont.text.trim();
      String address = addressCont.text.trim();
      String lattitude = lattitudeCont.text.trim();
      String longtitude = longtitudeCont.text.trim();
      String countryName = countryNameCont.text.trim();
      String countryCode = countryCodeCont.text.trim();
      String fcmToken = '';

      await addUserData(
          context: context,
          firstName: firstName,
          lastName: lastName,
          userName: userName,
          mono: mono,
          address: address,
          lattitude: lattitude,
          longtitude: longtitude,
          countryName: countryName,
          countryCode: countryCode,
          fcmToken: '',
          profilePic: imgUint8list != null ? [imgUint8list!] : []);
    }
  }

  UpdateUserApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      String firstName = firstNameCont.text.trim();
      String lastName = lastNameCont.text.trim();
      String userName = userNameCont.text.trim();
      String mono = monoCont.text.trim();
      String address = addressCont.text.trim();
      String lattitude = lattitudeCont.text.trim();
      String longtitude = longtitudeCont.text.trim();
      String countryName = countryNameCont.text.trim();
      String countryCode = countryCodeCont.text.trim();
      String fcmToken = '';
      await updateUserData(
          context: context,
          userId: widget.userData!.id,
          firstName: firstName,
          lastName: lastName,
          userName: userName,
          mono: mono,
          address: address,
          lattitude: lattitude,
          longtitude: longtitude,
          countryName: countryName,
          countryCode: countryCode,
          fcmToken: fcmToken,
          profilePic: imgUint8list != null ? [imgUint8list!] : []);
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
          Text(isUpdate ? 'Update User' : "Add User Details",
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
                                  Text("First Name", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: firstNameCont,
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
                                  Text("Last Name", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: lastNameCont,
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
                        Text("User name", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: userNameCont,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Mobile Number", style: primaryTextStyle()),
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
                        Text("Address", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: addressCont,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
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
                            SizedBox(width: 10),
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
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Country Code",
                                      style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: countryCodeCont,
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
                                  Text("Country Name",
                                      style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: countryNameCont,
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
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            Text("Add Image", style: primaryTextStyle()),
                            SizedBox(height: 16),
                            SizedBox(
                              width: 120,
                              height: 40,
                              child: ElevatedButton(
                                style: ElevatedButton.styleFrom(
                                    shape: RoundedRectangleBorder(
                                        borderRadius: BorderRadius.circular(
                                            8.0),
                                        side: BorderSide(color: viewLineColor)),
                                    elevation: 0,
                                    backgroundColor: Colors.transparent,
                                    shadowColor: Colors.transparent),
                                child: Text("Select File",
                                    style: boldTextStyle(color: Colors.grey)),
                                onPressed: () {
                                  getImage();
                                },
                              ),
                            ),
                            SizedBox(height: 10),
                            SelectedImageViewer(
                                res: imgUint8list != null ? [imgUint8list!] : [
                                ], setState: setState),
                            SizedBox(height: 16),
                          ],
                        ),
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
          isUpdate ? UpdateUserApi() : AddUser();
        }),
      ],
    );
  }
}
// title
// location
// lattitude
// longtitude
// eventDate
// time
// description
// mono